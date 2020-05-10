#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

DWORD GetPID(const char* ProcessName) {
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);


	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!strcmp(processInfo.szExeFile, ProcessName))
	{
		CloseHandle(processesSnapshot);
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!strcmp(processInfo.szExeFile, ProcessName))
		{
			CloseHandle(processesSnapshot);
		}
	}
	CloseHandle(processesSnapshot);
	return processInfo.th32ProcessID;
}

MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID) {
	MODULEENTRY32 modEntry = { 0 };

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 curr = { 0 };

		curr.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &curr))
		{
			do
			{
				if (!strcmp(curr.szModule, moduleName))
				{
					modEntry = curr;
					break;
				}
			} while (Module32Next(hSnapshot, &curr));
		}
		CloseHandle(hSnapshot);
	}
	return modEntry;
}

int main()
{
    std::cout << "How to add offsets to addresses in C++!\n"; 
	unsigned long long pid = GetPID("ac_client.exe");
	MODULEENTRY32 module = GetModule("ac_client.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	//Example of adding offests one line at a time:
	unsigned long long result;
	int NewAmmoValue = 1337;
	ReadProcessMemory(phandle, (void*)((unsigned long long)module.modBaseAddr + 0x0010F418), &result, sizeof(result), 0); //"ac_client.exe" + 0x0010F418
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x58), &result, sizeof(result), 0); //result + 0x58
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x2B4), &result, sizeof(result), 0); //result + 0x2B4
	WriteProcessMemory(phandle, (void*)((unsigned long long)result + 0x10), &NewAmmoValue, sizeof(NewAmmoValue), 0); //result + 0x10
	//full pointer: "ac_client.exe" + 0x0010F418 + 0x58 + 0x2B4 + 0x10
	system("pause");

	
}