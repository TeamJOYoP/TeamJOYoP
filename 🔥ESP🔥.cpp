
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/socket.h>
#include <malloc.h>
#include <math.h>


#ifndef __UTF_H__
#define __UTF_H__
#define FALSE 0
#define TRUE 1
#define halfShift 10
#define UNI_SUR_HIGH_START (UTF32)0xD800
#define UNI_SUR_HIGH_END (UTF32)0xDBFF
#define UNI_SUR_LOW_START (UTF32)0xDC00
#define UNI_SUR_LOW_END (UTF32)0xDFFF
	
#define UNI_REPLACEMENT_CHAR (UTF32)0x0000FFFD
#define UNI_MAX_BMP (UTF32)0x0000FFFF
#define UNI_MAX_UTF16 (UTF32)0x0010FFFF
#define UNI_MAX_UTF32 (UTF32)0x7FFFFFFF
#define UNI_MAX_LEGAL_UTF32 (UTF32)0x0010FFFF
typedef unsigned char boolean;
typedef unsigned int CharType;
typedef char UTF8;
typedef unsigned short UTF16;
typedef unsigned int UTF32;

static const UTF32 halfMask = 0x3FFUL;
static const UTF32 halfBase = 0x0010000UL;
static const UTF8 firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
static const UTF32 offsetsFromUTF8[6] =
	{ 0x00000000UL, 0x00003080UL, 0x000E2080UL, 0x03C82080UL, 0xFA082080UL, 0x82082080UL };
static const char trailingBytesForUTF8[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5
};

typedef enum
{
	strictConversion = 0,
	lenientConversion
}
ConversionFlags;
typedef enum
{
	conversionOK,			
	sourceExhausted,		
	targetExhausted,		
	sourceIllegal,				
	conversionFailed
}
ConversionResult;
#endif

int Utf16_To_Utf8(const UTF16 * sourceStart, UTF8 * targetStart, size_t outLen,
				  ConversionFlags flags)
{
	int result = 0;
	const UTF16 *source = sourceStart;
	UTF8 *target = targetStart;
	UTF8 *targetEnd = targetStart + outLen;
	if ((NULL == source) || (NULL == targetStart))
	{
		
		return conversionFailed;
	}

	while (*source)
	{
		UTF32 ch;
		unsigned short bytesToWrite = 0;
		const UTF32 byteMask = 0xBF;
		const UTF32 byteMark = 0x80;
		const UTF16 *oldSource = source;	
		
		ch = *source++;
	
		if (ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_HIGH_END)
		{
		
			if (*source)
			{
				UTF32 ch2 = *source;
				
				if (ch2 >= UNI_SUR_LOW_START && ch2 <= UNI_SUR_LOW_END)
				{
					ch = ((ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) +
						halfBase;
					++source;
				}
				else if (flags == strictConversion)
				{			
					--source;
					result = sourceIllegal;
					break;
				}
			}
			else
			{					
				--source;		
				result = sourceExhausted;
				break;
			}
		}
		else if (flags == strictConversion)
		{
			if (ch >= UNI_SUR_LOW_START && ch <= UNI_SUR_LOW_END)
			{
				--source;		
				result = sourceIllegal;
				break;
			}
		}

		if (ch < (UTF32) 0x80)
		{
			bytesToWrite = 1;
		}
		else if (ch < (UTF32) 0x800)
		{
			bytesToWrite = 2;
		}
		else if (ch < (UTF32) 0x10000)
		{
			bytesToWrite = 3;
		}
		else if (ch < (UTF32) 0x110000)
		{
			bytesToWrite = 4;
		}
		else
		{
			bytesToWrite = 3;
			ch = UNI_REPLACEMENT_CHAR;
		}
		target += bytesToWrite;
		if (target > targetEnd)
		{
			source = oldSource;	
			target -= bytesToWrite;
			result = targetExhausted;
			break;
		}
		switch (bytesToWrite)
		{		
		case 4:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 3:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 2:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 1:
			*--target = (UTF8) (ch | firstByteMark[bytesToWrite]);
		}
		target += bytesToWrite;
	}
	return result;
}

typedef char PACKAGENAME;

int isapkrunning(PACKAGENAME *bm)
{
	DIR *dir=NULL;
	struct dirent *ptr=NULL;
	FILE *fp=NULL;
	char filepath[50];			
	char filetext[128];			
	dir = opendir("/proc/");		
	if (dir != NULL)
	{
		while ((ptr = readdir(dir)) != NULL)	
		{
			
			if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
				continue;
			if (ptr->d_type != DT_DIR)
				continue;
			sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);	
			fp = fopen(filepath, "r");	
			if (NULL != fp)
			{
				fgets(filetext,sizeof(filetext),fp);	
				if (strcmp(filetext,bm)==0)
				{
					closedir(dir);
					return 1;
				}
				fclose(fp);
			}
		}
	}
	closedir(dir);	
	return 0;
}
int getPID(const char *packageName)
{
	int id = -1;
	DIR *dir;
	FILE *fp;
	char filename[64];
	char cmdline[64];
	struct dirent *entry;
	dir = opendir("/proc");
	while ((entry = readdir(dir)) != NULL)
	{
		id = atoi(entry->d_name);
		if (id != 0)
		{
			sprintf(filename, "/proc/%d/cmdline", id);
			fp = fopen(filename, "r");
			if (fp)
			{
				fgets(cmdline, sizeof(cmdline), fp);
				fclose(fp);
				if (strcmp(packageName, cmdline) == 0)
				{
					return id;
				}
			}
		}
	}
	closedir(dir);
	return -1;
}

long int get_module_base(int pid, const char *module_name)
{
	FILE *fp;
	long addr = 0;
	char *pch;
	char filename[64];
	char line[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (fgets(line, sizeof(line), fp))
		{
			if (strstr(line, module_name))
			{
				pch = strtok(line, "-");
				addr = strtoul(pch, NULL, 16);
				if (addr == 0x8000)
					addr = 0;
				break;
			}
		}
		fclose(fp);
	}
	return addr;
}

long int handle;
float getFloat(long int addr)
{
	float var = 0;
	pread64(handle, &var, 4, addr);
	return var;
}

int getDword(long int addr)
{
	int var = 0;
	pread64(handle, &var, 4, addr);
	return var;
}

long int getZZ(long int addr)
{
	long int var = 0;
	pread64(handle, &var, 4, addr);
	return var;
}

void getCharacterName(UTF8 * transcoding, long int addr)
{
	int classname;
	int m = 0;
	UTF8 buf88[256] = "";
	long int namepy = getZZ(addr + 0x638);
	UTF16 buf16[34] = {
		0
	};
	int hex[2] = {
		0
	};
	for (int i = 0; i < 4; i++)
	{
		classname = getZZ(namepy + i * 4);
		hex[0] = (classname & 0xfffff000) >> 16;
		hex[1] = classname & 0xffff;
		buf16[m] = hex[1];
		buf16[m + 1] = hex[0];
		m += 2;
	}
	Utf16_To_Utf8(buf16, buf88, sizeof(buf88), strictConversion);
	sprintf(transcoding, "%s", buf88);
}
long int Gworld = 0, ViewWorld = 0;
int main(int argc, char **argv)
{
int  ipid;
  int pkg_beta; 
  int pkg_lite; 
  int pkg_korean; 	   
  int pkg_global; 
	
 
  pkg_global  = isapkrunning("com.tencent.ig"); 		   
  pkg_lite = isapkrunning("com.tencent.iglite");
  pkg_korean = isapkrunning("com.pubg.krmobile");
  pkg_beta = isapkrunning("com.tencent.iglitece");



FILE *fp0 = fopen("/sdcard/SecVers.ini", "r");
  char py0;
  fscanf(fp0, "%s", &py0);
     
  
  if (strcmp(&py0, "18889") == 0) {
    
     if ( pkg_global == 1 )
  {
         Gworld = 0x6E208CC;
	     ViewWorld = 0x7291B68;	
   ipid = getPID("com.tencent.ig");
  }
  else if ( pkg_beta == 1 )
  {
         Gworld = 0x6E208CC;
		 ViewWorld = 0x7291B68;		    
   ipid = getPID("com.tencent.iglitece");
  }
  else if ( pkg_korean == 1 )
  {
        Gworld = 0x6E208CC;
		ViewWorld = 0x7291B68;		    
   ipid = getPID("com.pubg.krmobile");
  }
  else
  {
    if ( pkg_lite != 1 )
    {
   
      puts("PUBGM is not running");
      return 0;
    }
   
      Gworld = 0x6E208CC;
	  ViewWorld = 0x7291B68;		    
     ipid = getPID("com.tencent.iglite");
  }

    
} else {
   
}
 
	
	char lj[64];
	sprintf(lj, "/proc/%d/mem", ipid);
	handle = open(lj, O_RDWR);
	if (handle == 0)
	{
		puts("获取mem失败!");
		exit(1);
	}
	float matrix[50], px, py, angle;
	int scwq;

	
	FILE *fp = fopen("/sdcard/x.log", "r");
	FILE *fp1 = fopen("/sdcard/y.log", "r");
	if (fp == NULL || fp1 == NULL)	
	{
		px = 1080.0;
		py = 2340.0;
	}
	else
	{
		fscanf(fp, "%f", &px);
		fscanf(fp1, "%f", &py);
		if (py > px)
		{
			float t = px;
			px = py;
			py = t;
		}
		py = py / 2.0;
		px = px / 2.0;
		fclose(fp);
		fclose(fp1);
	}

	
 puts("\n\n☠•••••••••••••••••••••••⊹⊱✫⊰⊹•••••••••••••••••••••••☠\CPP MODE BY TeamJÔYoP☠•••••••••••••••••••••••⊹⊱✫⊰⊹•••••••••••••••••••••••☠\n\n");
	char mname[] = "libUE4.so";	
	long int libbase = get_module_base(ipid, mname);


long int Matrix = getZZ(getZZ(libbase + ViewWorld) + 0x68) + 0x2A0;	


	FILE *F;
	while ((F = fopen("/sdcard/停止.log", "r")) == NULL)	
	{
		char aaa[30720] = "";	
		char b[256];

		long int Uworld = getZZ(libbase + Gworld);	
		long int oneself = getZZ(getZZ(getZZ(getZZ(Uworld + 0x24) + 0x60) + 0x20) + 0x320);
		long int team = getDword(oneself + 0x660);	
		long int Uleve = getZZ(Uworld + 0x20);	
		long int arrayaddr = getZZ(Uleve + 0x70);	
		long int count = getDword(Uleve + 0x74);	
		

		
		for (int i = 0; i < 16; i++)
		{
			float matrixaddr = getFloat(Matrix + i * 4);
			matrix[i] = matrixaddr;
		}

		
		for (int i = 0; i < count; i++)
		{
			long int objaddrzz = getZZ(arrayaddr + 4 * i);	

		
			float wzzb = getFloat(objaddrzz + 0x1764);
			if (wzzb != 479.5)
			{
				continue;
			}					

		
			int dw = getDword(objaddrzz + 0x660);

		
		if (team == dw)		
		{
				continue;
			}

			long int object = getZZ(objaddrzz + 0x140);	

		
			float z_x = getFloat(Matrix - 0x10);
			float z_y = getFloat(Matrix - 0xC);
			float z_z = getFloat(Matrix - 0x8);

			
			float d_x = getFloat(object + 0xFC);
			float d_y = getFloat(object + 0x100);
			float d_z = getFloat(object + 0x104);

			
			float jl = sqrt(pow(d_x - z_x, 2) + pow(d_y - z_y, 2) + pow(d_z - z_z, 2)) * 0.01;
			if (jl > 400)
			{
				continue;
			}					

		
			float camear_r = matrix[3] * d_x + matrix[7] * d_y + matrix[11] * d_z + matrix[15];
			float r_x =
				px + (matrix[0] * d_x + matrix[4] * d_y + matrix[8] * d_z +
					  matrix[12]) / camear_r * px;
			float r_y =
				py - (matrix[1] * d_x + matrix[5] * d_y + matrix[9] * (d_z - 5) +
					  matrix[13]) / camear_r * py;
			float r_w =
				py - (matrix[1] * d_x + matrix[5] * d_y + matrix[9] * (d_z + 205) +
					  matrix[13]) / camear_r * py;

		
			UTF8 Name[32] = "";
			getCharacterName(Name, objaddrzz);

			
			float hp = getFloat(objaddrzz + 0x918);

		
			int bot = getDword(objaddrzz + 0x6d8);

		
			int dz = getDword(objaddrzz + 0x878);

			
			sprintf(b, "%f,%f,%f,%f,%f,%f,%d,%d,%d,%s,%f;\n", r_x - (r_y - r_w) / 4,	
					r_y,		
					(r_y - r_w) / 2,	
					r_y - r_w,	
					jl,			
					hp,			
					bot,	
					dz,			
					dw,			
					Name,	
					hp
				);
			strcat(aaa, b);
		}

		int fd = open("/sdcard/b.log", O_WRONLY | O_CREAT);
		write(fd, aaa, sizeof(aaa));	
		close(fd);
		usleep(50);
	}
}