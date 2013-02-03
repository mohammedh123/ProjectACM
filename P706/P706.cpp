// Solution to problem 706
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <string>

using namespace std;

class P706
{
    static void AddCharVerticalLine(string* stringArr, int y, int height, char ch)
    {
        for(int r = 0; r < height; r++) {
            stringArr[y+r].push_back(ch);
        }
    }

    static void AddCharHorizontalLine(string* stringArr, int y, int width, char ch)
    {
        for(int r = 0; r < width; r++) {
            stringArr[y].push_back(ch);
        }
    }

    static void AddHorizontalLineSansOne(string* stringArr, int y, int width, char ch)
    {
        stringArr[y].push_back(' ');
        AddCharHorizontalLine(stringArr, y, width, ch);
        stringArr[y].push_back(' ');
    }

    static void AddLoneLeftSide(string* stringArr, int y, int height, int digitWidth, char ch)
    {
        for(int r = 0; r < height; r++) {
            stringArr[y+r].push_back(ch);

            for(int j = 1; j < digitWidth; j++) {
                stringArr[y+r].push_back(' ');
            }
        }
    }

    static void AddLoneRightSide(string* stringArr, int y, int height, int digitWidth, char ch)
    {
        for(int r = 0; r < height; r++) {
            for(int j = 1; j < digitWidth; j++) {
                stringArr[y+r].push_back(' ');
            }

            stringArr[y+r].push_back(ch);
        }
    }

    static void AddBothLeftAndRightSide(string* stringArr, int y, int height, int digitWidth, char ch)
    {
        for(int r = 0; r < height; r++) {
            stringArr[y+r].push_back(ch);

            for(int j = 1; j < digitWidth-1; j++) {
                stringArr[y+r].push_back(' ');
            }

            stringArr[y+r].push_back(ch);
        }
    }

    static void DrawNumber(const string& number, int size)
    {
        const int digitHeight = 2*size + 3;
        const int digitWidth = size+2;
        const int digitSpacing = 1;
        const int numDigits = number.size();
        const int midLineY = digitHeight / 2;
        const int botLineY = digitHeight-1;

        string* arr = new string[digitHeight]; //arr[0] is top row, arr[digitHeight-1] is the bottom row

        for(int i = 0; i < digitHeight; i++) {
            arr[i].reserve(digitWidth*numDigits + digitSpacing*(numDigits-1));
            arr[i] = "";
        }

        char digit;
        for(int i = 0; i < numDigits; i++)
        {
            digit = number[i];

            if(digit == '0') {
                AddHorizontalLineSansOne(arr, 0, size, '-');

                AddBothLeftAndRightSide(arr, 1, size, digitWidth, '|');
                AddCharHorizontalLine(arr, midLineY, digitWidth, ' ');
                AddBothLeftAndRightSide(arr, 1+midLineY, size, digitWidth, '|');

                AddHorizontalLineSansOne(arr, digitHeight-1, size, '-');
            }
            else if(digit == '1') {
                for(int r = 0; r < digitWidth - 1; r++) {
                    AddCharVerticalLine(arr, 0, digitHeight, ' ');
                }

                arr[0].push_back(' ');                
                AddCharVerticalLine(arr, 1, size, '|');
                arr[1+size].push_back(' ');
                AddCharVerticalLine(arr, 1+size+1, size, '|');
                arr[digitHeight-1].push_back(' ');                    
            }
            else if(digit == '2') {
                for(int i = 0; i < digitHeight; i += size+1) {                    
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddLoneRightSide(arr, 1, size, digitWidth, '|');
                AddLoneLeftSide(arr, 1+midLineY, size, digitWidth, '|');
            }
            else if(digit == '3') {
                for(int i = 0; i < digitHeight; i += size+1) {               
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddLoneRightSide(arr, 1, size, digitWidth, '|');
                AddLoneRightSide(arr, 1+midLineY, size, digitWidth, '|');
            }
            else if(digit == '4') {
                AddCharHorizontalLine(arr, 0, digitWidth, ' ');                
                AddBothLeftAndRightSide(arr, 1, size, digitWidth, '|');                
                AddHorizontalLineSansOne(arr, midLineY, size, '-');
                AddLoneRightSide(arr, 1+midLineY, size, digitWidth, '|');
                AddCharHorizontalLine(arr, botLineY, digitWidth, ' ');  
            }
            else if(digit == '5') {
                for(int i = 0; i < digitHeight; i += size+1) {               
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddLoneLeftSide(arr, 1, size, digitWidth, '|');
                AddLoneRightSide(arr, 1+midLineY, size, digitWidth, '|');
            }
            else if(digit == '6') {
                for(int i = 0; i < digitHeight; i += size+1) {               
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddLoneLeftSide(arr, 1, size, digitWidth, '|');
                AddBothLeftAndRightSide(arr, 1+midLineY, size, digitWidth, '|');
            }
            else if(digit == '7') {           
                AddHorizontalLineSansOne(arr, 0, size, '-');
                AddLoneRightSide(arr, 1, size, digitWidth, '|');
                AddCharHorizontalLine(arr, midLineY, digitWidth, ' ');
                AddLoneRightSide(arr, 1+midLineY, size, digitWidth, '|');
                AddCharHorizontalLine(arr, botLineY, digitWidth, ' ');
            }
            else if(digit == '8') {		    
                for(int i = 0; i < digitHeight; i += size+1) {               
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddBothLeftAndRightSide(arr, 1, size, digitWidth, '|');
                AddBothLeftAndRightSide(arr, 1+midLineY, size, digitWidth, '|');
            }
            else if(digit == '9') {
                for(int i = 0; i < digitHeight; i += size+1) {               
                    AddHorizontalLineSansOne(arr, i, size, '-');
                }

                AddBothLeftAndRightSide(arr, 1, size, digitWidth, '|');
                AddLoneRightSide(arr, 1+midLineY, size, digitWidth, '|');
            }

            if(i != numDigits - 1) {
                // add a vertical blank between digits
                AddCharVerticalLine(arr, 0, digitHeight, ' ');
            }
        }

        for(int i = 0; i < digitHeight; i++) {
            cout << arr[i] << endl;
        }

        delete[] arr;
    }

public:
    static void Solve()
    {	
        int size;
        string number;

        while(cin >> size >> number) {
            if(size == 0 && number == "0") {
                //cout << endl;
                break;
            }

            DrawNumber(number, size);
            cout << endl;
        }
    }
};

int main()
{
    P706::Solve();
}