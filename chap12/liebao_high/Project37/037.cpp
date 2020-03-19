#include<stdio.h>

class BadSrcFile {};
class BadDestFile {};
class BadCopy{};

//传统方法
int my_cp(const char *src_file, const char *dest_file)	// 实现功能：从一个文件中拷贝到另一文件；
{
	FILE *in_file, *out_file; // 定义了两个文件指针

	in_file = fopen(src_file, "rb"); //以二进制读的形式打开文件src_file;
	if (in_file == NULL)
	{
		return 1;//如果读到的文件为空，或者没有能够打开文件则返回1;
	}

	out_file = fopen(dest_file, "wb"); //以二进制写的形式打开文件src_file;
	if (out_file == NULL)
	{
		return 2;
	}

	char rec[256]; //先定义一个256字节的rec，用来缓冲，先将文件读到rec中，读取文件一次最多读取256字节，然后再从rec写到文件中；
	size_t bytes_in, bytes_out;
	while ((bytes_in = fread(rec,1,256,in_file)) > 0) //每次读一个字节，读256个，bytes_in为实际读到的字节数，如果最后不足256就读取实际剩余的字节，如果返回为0，说明文件已读完；
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);//将读取到的字节写入文件中；
		if (bytes_in != bytes_out)
		{
			return 3;
		}
	}

	fclose(in_file);
	fclose(out_file);//关闭文件；
	return 0;
}

//使用异常 ，可以不需要返回值；throw 的类型为数字；
void my_cp2(const char *src_file, const char *dest_file)	// 实现功能：从一个文件中拷贝到另一文件；
{
	FILE *in_file, *out_file; // 定义了两个文件指针

	in_file = fopen(src_file, "rb"); //以二进制读的形式打开文件src_file;
	if (in_file == NULL)
	{
		//return 1;//如果读到的文件为空，或者没有能够打开文件则返回1;
		throw 1; //使用抛出异常的方式；throw的可以是数字，字符串，也可以是类对象，此处使用数字；
	}

	out_file = fopen(dest_file, "wb"); //以二进制写的形式打开文件src_file;
	if (out_file == NULL)
	{
		//return 2;
		throw 2;
	}

	char rec[256]; //先定义一个256字节的rec，用来缓冲，先将文件读到rec中，读取文件一次最多读取256字节，然后再从rec写到文件中；
	size_t bytes_in, bytes_out;
	while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) //每次读一个字节，读256个，bytes_in为实际读到的字节数，如果最后不足256就读取实际剩余的字节，如果返回为0，说明文件已读完；
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);//将读取到的字节写入文件中；
		if (bytes_in != bytes_out)
		{
			//return 3;
			throw 3;
		}
	}
	fclose(in_file);
	fclose(out_file);//关闭文件；
}

//使用异常 ，可以不需要返回值；throw 的类型为字符串；
void my_cp3(const char *src_file, const char *dest_file)	// 实现功能：从一个文件中拷贝到另一文件；
{
	FILE *in_file, *out_file; // 定义了两个文件指针

	in_file = fopen(src_file, "rb"); //以二进制读的形式打开文件src_file;
	if (in_file == NULL)
	{
		//return 1;//如果读到的文件为空，或者没有能够打开文件则返回1;
		throw "打开源文件时出错。";
	}

	out_file = fopen(dest_file, "wb"); //以二进制写的形式打开文件src_file;
	if (out_file == NULL)
	{
		//return 2;
		throw "打开目标文件时出错。";
	}

	char rec[256]; //先定义一个256字节的rec，用来缓冲，先将文件读到rec中，读取文件一次最多读取256字节，然后再从rec写到文件中；
	size_t bytes_in, bytes_out;
	while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) //每次读一个字节，读256个，bytes_in为实际读到的字节数，如果最后不足256就读取实际剩余的字节，如果返回为0，说明文件已读完；
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);//将读取到的字节写入文件中；
		if (bytes_in != bytes_out)
		{
			//return 3;
			throw "拷贝时出错。";
		}
	}
	fclose(in_file);
	fclose(out_file);//关闭文件；
}

//使用异常 ，可以不需要返回值；throw 的类型为类对象；
void my_cp4(const char *src_file, const char *dest_file)	// 实现功能：从一个文件中拷贝到另一文件；
{
	FILE *in_file, *out_file; // 定义了两个文件指针

	in_file = fopen(src_file, "rb"); //以二进制读的形式打开文件src_file;
	if (in_file == NULL)
	{
		//return 1;//如果读到的文件为空，或者没有能够打开文件则返回1;
		throw BadSrcFile();
	}

	out_file = fopen(dest_file, "wb"); //以二进制写的形式打开文件src_file;
	if (out_file == NULL)
	{
		//return 2;
		throw BadDestFile();
	}

	char rec[256]; //先定义一个256字节的rec，用来缓冲，先将文件读到rec中，读取文件一次最多读取256字节，然后再从rec写到文件中；
	size_t bytes_in, bytes_out;
	while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) //每次读一个字节，读256个，bytes_in为实际读到的字节数，如果最后不足256就读取实际剩余的字节，如果返回为0，说明文件已读完；
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);//将读取到的字节写入文件中；
		if (bytes_in != bytes_out)
		{
			//return 3;
			throw BadCopy();
		}
	}
	fclose(in_file);
	fclose(out_file);//关闭文件；
}

int main()
{
	int result;
	if ((result = my_cp("e:\\1.txt", "e:\\2.txt")) != 0)
	{
		switch (result)
		{
		case 1:
			printf("打开源文件时出错！\n");
			break;
		case 2:
			printf("打开目标文件时出错！\n");
			break;
		case 3:
			printf("拷贝文件时出错！\n");
			break;
		default:
			printf("发生未知错误！\n");
			break;
		}
	}

	try //将可能发生异常的代码放在此处的大括号内；
	{
		my_cp2("e:\\1.txt", "e:\\3.txt");
		my_cp3("e:\\1.txt", "e:\\4.txt");
		my_cp4("e:\\11.txt", "e:\\5.txt");
	}
	catch (int e) //对异常进行捕获；
	{
		printf("发生异常：%d\n", e);//此处的e就是发生异常对应的数字，也就是上面throw出的数字；也可以像上面的case对异常情况进行输出；
	}
	catch (const char * e)//对异常进行捕获；
	{
		printf("%s\n", e);
	}
	catch (BadSrcFile e)
	{
		printf("发生异常：打开源文件时出错！\n");
	}
	catch (BadDestFile e)
	{
		printf("发生异常：打开目标文件时出错！\n");
	}
	catch (BadCopy e)
	{
		printf("发生异常：拷贝时出错！\n");
	}
	catch (...) //对所有的异常进行捕获，可以不要前面的catch的情况；
	{
		printf("发生了未知异常。");
	}

	printf("OK!\n");
	return 0;
}