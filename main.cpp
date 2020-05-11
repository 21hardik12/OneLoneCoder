#include <iostream>
#include <windows.h>

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlaterX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14159F / 4.0f;
float fDepth = 16.0f;

int main {
	//Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	return 0;

	wstring map;
	map += "################";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "#..............#";
	map += "################";

	// Game Loop
	while (1) {
		for (int i = 0; i < nScreenWidth; i++) {
			float fRayAngle = (fPlayerA - fFOV/2.0f) + (float(x)/float(nScreenWidth)) * fFOV;
			float fDistanceToWall = 0;
			bool bHitWall = false;

			float fEyeX = sinf(fRayAngle);
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// test if the ray is out of bounds
				if (nTestX < 0 || nTestX >= nMapWidth || ntestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true;
					fDistanceToWall = fDepth;
				} else {
					// we are within the bounds and need to check if the character is a wall
					if (map[nTestY * nMapWidth + nTestX] == '#') {
						bHitWall = true;
					}
				}
			}
		}

		// for writing to the buffer
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0, 0}, dwBytesWritten);
	}
}
