#include <windows.h>
#include <iostream>

int main()
{
    // Initial Presentation
    std::cout << "==========================================\n";
    std::cout << " Agility SDK Version Verifier by Warkratos\n";
    std::cout << "==========================================\n\n";

	// Loads the system DLL that contains the SDK version variable
    HMODULE hMod = LoadLibraryA("C:\\Windows\\System32\\D3D12Core.dll");

    if (hMod)
    {
        UINT* sdkVersion = (UINT*)GetProcAddress(hMod, "D3D12SDKVersion");
        if (sdkVersion)
        {
			// Gets the console handle to change text color
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			// Prints the message before the version number
            std::cout << "Your Windows Agility SDK Version -> ";

			// Change the text color to bright green for the version number
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

			// Prints the SDK version number
            std::cout << *sdkVersion << std::endl;

			// Restores the default console text color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }
        else
        {
            std::cout << "Warning: Impossible to find SDK Version in the file." << std::endl;
        }
        FreeLibrary(hMod);
    }
    else
    {
        std::cout << "Error: Impossible to load D3D12Core.dll in this system." << std::endl;
    }

    std::cout << "\n";

	// Pauses the console to allow the user to read the output before it closes
    system("pause");

    return 0;
}
