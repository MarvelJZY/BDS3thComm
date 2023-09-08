using namespace std;

#include <vector>
#include <iostream>

#include <bitset>
#include <iomanip>
#include "BDSInfo_Send.h"
#include<sstream>//int转string

string int_string(int a)
{
	//int转string
	stringstream st;
	st << a;
	string str = st.str();
	return str;
}
LPCWSTR stringToLPCWSTR(string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}

void OriDecode(string str)
{
	string comparestr;
	//按照消息类型进入不同的处理
	comparestr = str.substr(0, 6);
	if (comparestr == "$BDEPI")//类型1
	{
		string DbsSplited[14] = {};//保存分割后的数组
		string* p = DbsSplited;

		SenEPI* epi = new SenEPI();
		epi->SplitEPI(str, p);//语句分割
		epi->message_type = *p;
		epi->send_id = *(p + 1);
		epi->recv_id = *(p + 2);
		epi->serv_type = *(p + 3);
		epi->time = *(p + 4);
		epi->lon = *(p + 5);
		epi->lon_mark = *(p + 6);
		epi->lat = *(p + 7);
		epi->lat_mark = *(p + 8);
		epi->height = *(p + 9);
		epi->secure_type = *(p + 10);
		epi->command_type = *(p + 11);

		epi->secure_data_len = *(p + 12);
		//epi->state_data_len = *(p + 13);
		epi->state_data = *(p + 13);

		epi->DecodeEPI(epi, p);//语句解析

		delete epi;
	}

	else if (comparestr == "$BDTCI")//类型2
	{
		string DbsSplited[8] = {};//保存分割后的数组
		string* p = DbsSplited;

		SenTCI* tci = new SenTCI();
		tci->SplitTCI(str, p);//语句分割
		tci->message_type = *p;
		tci->send_id = *(p + 1);
		tci->recv_id = *(p + 2);
		tci->time = *(p + 3);
		tci->code_type = *(p + 4);
		tci->data_mark = *(p + 5);
		tci->com_len = *(p + 6);
		tci->com_data = *(p + 7);
		tci->DecodeTCI(tci, p);//语句解析
		delete tci;
	}

	else if (comparestr == "$BDSHZ")//类型3
	{
		string DbsSplited[14] = {};//保存分割后的数组
		string* p = DbsSplited;

		SenSHZ* shz = new SenSHZ();
		shz->SplitSHZ(str, p);//语句分割
		shz->message_type = *p;
		shz->send_id = *(p + 1);
		shz->recv_id = *(p + 2);
		shz->serv_type = *(p + 3);
		shz->time = *(p + 4);
		shz->lon = *(p + 5);
		shz->lon_mark = *(p + 6);
		shz->lat = *(p + 7);
		shz->lat_mark = *(p + 8);
		shz->height = *(p + 9);
		shz->secure_type = *(p + 10);
		shz->command_type = *(p + 11);

		shz->secure_data_len = *(p + 12);
		//epi->state_data_len = *(p + 13);
		shz->state_data = *(p + 13);

		shz->DecodeSHZ(shz, p);//语句解析

		delete shz;
	}

	else if (comparestr == "$BDRTI")//类型4
	{
		//SenEPI epi;
		//epi.SplitSAK(str);
	}
	else
		cout << "并非目标信息" << endl;
}

int main()
{
	//配置
	int com = 0;
	cout << "请输入目标端口号：";
	cin >> com;
	string strcomm = "COM";
	strcomm = strcomm + int_string(com);
	// 打开串口
	HANDLE hComm = CreateFile(stringToLPCWSTR(strcomm), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
	if (hComm == INVALID_HANDLE_VALUE)
	{
		std::cerr << "Failed to open the serial port." << endl;
		return 1;
	}

	// 设置串口参数
	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (!GetCommState(hComm, &dcbSerialParams))
	{
		cerr << "Failed to get the current serial port configuration." << endl;
		CloseHandle(hComm);
		return 1;
	}
	dcbSerialParams.BaudRate = 19200;  // 设置波特率为 9600
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	if (!SetCommState(hComm, &dcbSerialParams))
	{
		cerr << "Failed to set the serial port configuration." << endl;
		CloseHandle(hComm);
		return 1;
	}
	system("pause");
	system("CLS");
	// 读取串口数据
	DWORD dwRead;
	char buff[1];
	char bds_data[] = { 0 };
	int data_type = 0;
	//cout << "请输入发送的数据：" << endl;
	//cin >> bds_data;

	char test[] = { "$BDEPI,x.x,x.x,x,hhmmss.ss,yyyyy.yy,c,llll.ll,c,x.x,x,x,x.x,c--c*hh\r\n" };
	while (true)
	{
		cout << "*****************" << "\n" << "1.应急搜救和位置报告申请EPQ" << "\n" << "2.报文通信申请TCQ" << "\n" << "3.位置查询申请PSQ" << "\n" << "4.测试" << "\n" << "*****************" << "\n" << "输入发送的数据类型:";
		cin >> data_type;

		switch (data_type)
		{
		case 1://EPQ
		{
			cout << "功能未实现" << endl;
			system("pause");
			system("CLS");
			break;
		}
		case 2://TCQ
		{
			cout << "功能未实现" << endl;
			system("pause");
			system("CLS");
			break;
		}
		case 3: //PSQ
		{
			SenPSQ* psq = new SenPSQ();
			psq->EncodePSQ(psq, hComm);
			delete psq;
			break;
		}
		case 4://测试
		{
			char testdata[] = { "$CCTXA,930370,1,1,68656C6C6F77686B*44" };
			if (!WriteFile(hComm, test, strlen(test), &dwRead, nullptr))
			{
				cerr << "Failed to write to serial port." << endl;
				CloseHandle(hComm);
				return 0;
			}
		}
		default:
		{
			cout << "非可用类型" << endl;
			system("pause");
			system("CLS");
			break;
		}
		}
		//cout << "输入发送的数据内容：";
		//cin >> bds_data;
		////向串口发送消息
		//if (!WriteFile(hComm, test, strlen(test), &dwRead, nullptr))
		//{
		//	cerr << "Failed to write to serial port." << endl;
		//	CloseHandle(hComm);
		//	return 0;
		//}
		Sleep(10000);
	}
	// 关闭串口
	CloseHandle(hComm);
	return 0;
}