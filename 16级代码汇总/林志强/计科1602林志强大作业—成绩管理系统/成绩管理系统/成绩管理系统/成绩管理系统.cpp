// �ɼ�����ϵͳ.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "Form1.h"
#include"LogForm.h"

using namespace �ɼ�����ϵͳ;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew Form1());

	return 0;
}
