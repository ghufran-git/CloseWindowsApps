/*
Made By Ghufran Ullah - robotics-dev
Made for Upwork 


*/

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

void ListProcesses()
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to create snapshot of running processes." << std::endl;
        return;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &processEntry))
    {
        std::cout << "Failed to retrieve the first process entry." << std::endl;
        CloseHandle(hSnapshot);
        return;
    }

    std::cout << "List of running processes:" << std::endl;

    do
    {
        std::wstring processName(processEntry.szExeFile);
        std::wcout << "Process ID: " << processEntry.th32ProcessID << std::endl;
        std::wcout << "Process Name: " << processName << std::endl;
        std::wcout << "-----------------------------------" << std::endl;
    } while (Process32Next(hSnapshot, &processEntry));

    CloseHandle(hSnapshot);
}

int main()
{
    ListProcesses();

    return 0;
}
