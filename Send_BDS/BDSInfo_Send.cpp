#include "BDSInfo_Send.h"

void SenEPI::SplitEPI(string str, string* p)
{
}

void SenEPI::DecodeEPI(SenEPI* epi, string* str)
{
}

void SenEPQ::GatherEPQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenEPQ::EncodeEPQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenTCI::SplitTCI(string str, string* p)
{

}

void SenTCI::DecodeTCI(SenTCI* tci, string* str)
{

}

void SenTCQ::GatherTCQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenTCQ::EncodeTCQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenSHZ::SplitSHZ(string str, string* p)
{

}

void SenSHZ::DecodeSHZ(SenSHZ* shz, string* str)
{

}

void SenPSQ::GatherPSQ(SenPSQ* psq, HANDLE hComm)
{
	cout << "function didnt realize!" << endl;
	

	//if (!WriteFile(hComm, query, strlen(query), &dwWrite, nullptr))
	//{
	//	cerr << "Failed to write to serial port." << endl;
	//	CloseHandle(hComm);
	//}
}

void SenPSQ::EncodePSQ(SenPSQ* psq, HANDLE hComm)
{
	cout << "正在获取卡号" << endl;
	char  query[] = "$CCICA,0,00*7B\n";//读取卡号命令
	DWORD dwWrite;
	DWORD dwRead;
	char buff[1];
	string tempbds;
	
	if (!WriteFile(hComm, query, strlen(query), &dwWrite, nullptr))
	{
		cerr << "Failed to write to serial port." << endl;
		CloseHandle(hComm);
	}
	// 读取串口数据到 szBuff 缓冲区
	else
	{
		while (true)
		{
			// 读取串口数据到 szBuff 缓冲区
			if (ReadFile(hComm, buff, 1, &dwRead, nullptr))
			{
				if (dwRead > 0)
				{
					if (buff[0] == '\n')//检测到回车则开始处理
					{
						if(tempbds.substr(0, 6)=="$BDICI")
						{
							psq->card_id = tempbds.substr(6, 7);
							cout << "卡号已获取:" << psq->card_id << endl;
							break;
						}
						tempbds.clear();
					}
					else
					{
						tempbds += buff[0];
					}
				}
			}
		}
		psq->GatherPSQ(psq, hComm);
	}

}

void SenSAK::SplitSAK(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenSAK::DecodeSAK(string str)
{
	cout << "function didnt realize!" << endl;
}

