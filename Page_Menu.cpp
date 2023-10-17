#include "Page_Menu.h"
#include "Console.h"
#include <iostream>

using namespace std;

Page_Menu::Page_Menu(){}


Page_Menu::~Page_Menu(){}

void Page_Menu::MainMenu()
{
	Console::setcolor(3);
	cout << "\n\n\n\n\n\n";
	cout << "            ::::::::::: :::::::::: ::::::::::: :::::::::  :::::::::::  ::::::::         ::::::::      :::     ::::    ::::  :::::::::: \n";
	cout << "                :+:     :+:            :+:     :+:    :+:     :+:     :+:    :+:       :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:        \n";
	cout << "                +:+     +:+            +:+     +:+    +:+     +:+     +:+              +:+         +:+   +:+  +:+ +:+:+ +:+ +:+        \n";
	cout << "                +#+     +#++:++#       +#+     +#++:++#:      +#+     +#++:++#++       :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   \n";
	cout << "                +#+     +#+            +#+     +#+    +#+     +#+            +#+       +#+   +#+# +#+     +#+ +#+       +#+ +#+        \n";
	cout << "                #+#     #+#            #+#     #+#    #+#     #+#     #+#    #+#       #+#    #+# #+#     #+# #+#       #+# #+#        \n";
	cout << "                ###     ##########     ###     ###    ### ###########  ########         ########  ###     ### ###       ### ########## \n\n\n\n";
	
	Console::setcolor(3);
	/*cout << "	 ##     ## ######## ##    ## ##     ##\n";
	cout << "	 ###   ### ##       ###   ## ##     ##\n";
	cout << "	 #### #### ##       ####  ## ##     ## \n";
	cout << "	 ## ### ## ######   ## ## ## ##     ## \n";
	cout << "	 ##     ## ##       ##  #### ##     ## \n";
	cout << "	 ##     ## ##       ##   ### ##     ## \n";
	cout << "	 ##     ## ######## ##    ##  #######  \n";*/

	Console::setcolor(15);
	short X =40;
	short Y = 15;
	Console::gotoXY(Y, X);
	cout << "           __ ___       __  ___         __         __             __ \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << " /|       (_   |   /\\  |__)  |    |\\ | |_  |  |   / _   /\\  |\\/| |_  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "  |  .    __)  |  /--\\ | \\   |    | \\| |__ |/\\|   \\__) /--\\ |  | |__ \n";
	Y += 2;
	Console::gotoXY(Y, X);
	cout << " __            __        __     __             __ \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "  _)      |   /  \\  /\\  |  \\   / _   /\\  |\\/| |_  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << " /__ .    |__ \\__/ /--\\ |__/   \\__) /--\\ |  | |__ \n";
	Y += 2;
	Console::gotoXY(Y, X);
	cout << " __               __        __  __  __   __   __  __ \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "  _)      |__| | / _  |__| (_  /   /  \\ |__) |_  (_  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << " __) .    |  | | \\__) |  | __) \\__ \\__/ | \\  |__ __) \n";
	Y += 2;
	Console::gotoXY(Y, X);
	cout << "                __      __  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "|__|      |__| |_  |   |__) \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "   | .    |  | |__ |__ |    \n";
	Y += 2;
	Console::gotoXY(Y, X);
	cout << "  __       __       ___ \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << " |_       |_  \\_/ |  |  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << " __) .    |__ / \\ |  |  \n";
}

void Page_Menu::PauseMenu()
{
}


void Page_Menu::Help()
{
	short Y, X;
	Console::setcolor(10);
	X = 23;
	Y = 3;
	Console::gotoXY(Y, X);
	cout << " __   __     __  __        __       __ ___  __                      __    __   __          __   __   __ \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "|  \\ /  \\   /   /  \\ |\\/| |__) |   |_   |  |_     /\\    |   | |\\ | |_    /  \\ |__)   |\\/| /  \\ |__) |_  \n";
	Y++;
	Console::gotoXY(Y, X);
	cout << "|__/ \\__/   \\__ \\__/ |  | |    |__ |__  |  |__   /--\\   |__ | | \\| |__   \\__/ | \\    |  | \\__/ | \\  |__ \n";
	Console::setcolor(6);
	cout << "\n\t\t\t\t\t\t ____    ____ \n";
	cout << "\t\t\t\t\t\t||<-||  ||->||\n";
	cout << "\t\t\t\t\t\t||__||  ||__||\t\tMove Tetrominoes\n";
	cout << "\t\t\t\t\t\t|/__\\|  |/__\\|\n";
	cout << "\t\t\t\t\t\t _____    ____ \n";
	cout << "\t\t\t\t\t\t||Up ||  ||X ||\n";
	cout << "\t\t\t\t\t\t||___||  ||__||\t\tRotate Right\n";
	cout << "\t\t\t\t\t\t|/___\\|  |/__\\|\n";
	cout << "\t\t\t\t\t\t ____    _______ \n";
	cout << "\t\t\t\t\t\t||Z ||  ||Ctrl ||\n";
	cout << "\t\t\t\t\t\t||__||  ||_____||\tRotate Left\n";
	cout << "\t\t\t\t\t\t|/__\\|  |/_____\\|\n";
	cout << "\t\t\t\t\t\t ____    _________ \n";
	cout << "\t\t\t\t\t\t||C ||  || SHIFT ||\n";
	cout << "\t\t\t\t\t\t||__||  ||_______||\tHold Tetromino\n";
	cout << "\t\t\t\t\t\t|/__\\|  |/_______\\|\n";
	cout << "\t\t\t\t\t\t _____ \n";
	cout << "\t\t\t\t\t\t||Esc||\n";
	cout << "\t\t\t\t\t\t||___||\t\t\tPause Game\n";
	cout << "\t\t\t\t\t\t|/___\\|\n";
	cout << "\t\t\t\t\t\t _____ \n";
	cout << "\t\t\t\t\t\t||Dn ||\n";
	cout << "\t\t\t\t\t\t||___||\t\t\tSoft drop (each line 1 point)\n";
	cout << "\t\t\t\t\t\t|/___\\|\n";
	cout << "\t\t\t\t\t\t ________________ \n";
	cout << "\t\t\t\t\t\t||              ||\n";
	cout << "\t\t\t\t\t\t||______________||\tHard drop (each line 2 point)\n";
	cout << "\t\t\t\t\t\t|/______________\\|\n";
	Console::setcolor(7);
	cout << "\n\n\t\t\t\t\t\t\t\t Press a key to skip...";
}
