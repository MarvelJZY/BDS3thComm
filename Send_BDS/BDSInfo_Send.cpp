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
	cout << "���ڻ�ȡ����" << endl;
	char  query[] = "$CCICA,0,00*7B\n";//��ȡ��������
	DWORD dwWrite;
	DWORD dwRead;
	char buff[1];
	string tempbds;
	
	if (!WriteFile(hComm, query, strlen(query), &dwWrite, nullptr))
	{
		cerr << "Failed to write to serial port." << endl;
		CloseHandle(hComm);
	}
	// ��ȡ�������ݵ� szBuff ������
	else
	{
		while (true)
		{
			// ��ȡ�������ݵ� szBuff ������
			if (ReadFile(hComm, buff, 1, &dwRead, nullptr))
			{
				if (dwRead > 0)
				{
					if (buff[0] == '\n')//��⵽�س���ʼ����
					{
						if(tempbds.substr(0, 6)=="$BDICI")
						{
							psq->card_id = tempbds.substr(6, 7);
							cout << "�����ѻ�ȡ:" << psq->card_id << endl;
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

