#include <iostream>
using namespace std;

class Printer
{
    string name;
    int available_paper;

public:
    Printer(string name, int paper)
    {
        name = name;
        available_paper = paper;
    }
    void Print(string txtDoc)
    {
        int reqPaper = txtDoc.length() / 10; // 40/10=4;
        if (reqPaper > available_paper)
        {
            throw "No Paper!";
            // return is redundant here
        }
        cout << "Printing..." << txtDoc << endl;
        available_paper -= reqPaper;
    }
};

int main()
{
    Printer myPrinter("HP DeskJet 1234", 10);
    try
    {
        myPrinter.Print("Hello, my name is Ahmed, I am a Software Engineer.");
        myPrinter.Print("Hello, my name is Ahmed, I am a Software Engineer.");
        myPrinter.Print("Hello, my name is Ahmed, I am a Software Engineer.");
    }
    catch (const char *txtException) // throw "text" is transferred to catch i.e. txtException
    {
        cout << "Exception: " << txtException << endl;
    }

    catch (int exCode)
    {
        cout << "Exception: " << exCode << endl;
    }

    catch (...) // // default catch block is always below const char* && int
    {
        cout << "Exception happened: " << endl;
    }
    return 0;
}
// Exception of type const char* is executed
