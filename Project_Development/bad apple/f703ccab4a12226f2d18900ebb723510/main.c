#include <stdio.h>
#include <windows.h>
//*****************************************************************************************
//******* oooooooooooooooooops ！ 收集者 Ryan****************
//*******源= http://tieba.baidu.com/p/1394998210 ****************
//*******联合开发网 2018.12.14****************
//*****************************************************************************************
void buffer_operate(char *buffer)
{
	int k = 0, i, j;
	for (i = 1; i != 0x18; i++) {
		for (j = 1; j != 0x4B; j++) {
			k = 0x4C * i + j;
			if (buffer[k] == 0x51) {
			   if ( buffer[k - 1] == 0x20 || buffer[k + 1] == 0x20 || buffer[k - 0x4C] == 0x20 || buffer[k + 0x4C] == 0x20 ) {
				   buffer[k] = rand() % 0x4B + 0x30;
			   }
            }
		}
	}
	return;
}

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[0], "rb");
	unsigned char string[] = {0x76, 0x78, 0x72, 0x60, 0x68, 0x63, 0xD4, 0xE1, 
                        0xC9, 0xC6, 0xD4, 0xE1, 0xB7, 0xF5, 0xB5, 0xAE, 
                        0xBA, 0xAC, 0xB4, 0xC3, 0xB6, 0xD5, 0xB7, 0xED, 
                        0xCE, 0xDE, 0xA2, 0xA0, 0xA2, 0xA0, 0xA2, 0xA0, 
                        0xA2, 0xA0, 0x00};
                        

	char buffer[2400];
	memset(buffer, 0, 2400);
	system("title Windows 控制台版动画 of Bad Apple ——Author: wysaid");
	puts("程序正在初始化，请稍后...");
	
	int i = 0;
	while (string[i] != '\0') {
		string[i]++;
		i++;
	}
	
	int j = 0;
	unsigned char rb_data;
	while (j < 34) {
		rb_data = fgetc(fp);
		if (string[j] == rb_data) { 
            j++;
        } else { 
            j = 0;
        }
	}

	int k, m;
	unsigned short int pos_x, pos_y;
	while (!feof(fp)) {
		j = 0;
		for (i = 0; i < 25; i++) {
			for (k = 0; k < 9; k++) {
				rb_data = fgetc(fp);
				for (m = 0; m != 8; m++) {
					if ((rb_data & (1 << (7 - m))) == 0) {
						buffer[j++] = 0x51;
					} else {
						buffer[j++] = 0x20;
					}
				}
			}
			rb_data = fgetc(fp);
			for (m = 0; m != 3; m++) {
				if ((rb_data & (1 << (7 - m))) == 0) {
					buffer[j++] = 0x51;
				} else {
					buffer[j++] = 0x20;
				}
			}
			buffer[j++] = 0x0A;
		}
		
		buffer[j - 1] = 0;
		buffer_operate(buffer);
		pos_x = 0;
		pos_y = 0;
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = pos_x;
		pos.Y = pos_y;
		//memcpy(&pos, &pos_x, 4);
		SetConsoleCursorPosition(hConsoleOutput, pos);
		printf(buffer);
		_sleep(125);
	}

	fclose(fp);
	system("cls");
	puts("动画结束！————本程序由wysaid制作，资源文件源文件来自网络，由wysaid压缩并处理成二进制文件。");
	return 0;
}
