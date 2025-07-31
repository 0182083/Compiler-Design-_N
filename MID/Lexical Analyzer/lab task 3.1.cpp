#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;


     const string  keywords[] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    // Define an array of C++ operators
    const string operators[] = { "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "&", "|", "^", "!", "~", "<<", ">>", "+=", "-="};

    // fucntion for check keyword

    bool isKeyword(string token)
    {
        for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i)
        {
            if (token == keywords[i])
            {
                return true;
            }
        }
        return false;
    }

    bool isOperator( string token)
    {
    // Iterate through each operator in the array
        for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); ++i)
        {
            if (token == operators[i])
            {
                return true;
            }
    }
    return false;
}

bool isIdentifier(string token)
{
    // Check if the token starts with a letter or underscore
    if (!isalpha(token[0]) && token[0] != '_') {
        return false;
    }

    // Check each character in the token
    for (char c : token) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }

    // If passed all checks, it's a valid identifier
    return true;
}




int main()
{
        // create and write to text file
    ofstream MyWriteFile("filename.txt");

    if (MyWriteFile.is_open())
       {
        MyWriteFile << "int main() {\n";
        MyWriteFile << "   int a = 10;\n";
        MyWriteFile << "   if (a > 5) return 1;\n";
        MyWriteFile << "   else return 0;\n";
        MyWriteFile << "}\n";
        MyWriteFile << "a\n";

        MyWriteFile.close();
       }
       else
       {
           cout<< "unable to open file"<<endl;
           return 1;
       }


    // Read the text file

    ifstream MyReadFile("filename.txt");
    string line;

    if(MyReadFile.is_open())
    {
        while (getline(MyReadFile,line))
        {
            istringstream tokenStream(line);
            string token;

            while(tokenStream>>token)
            {
                if (isKeyword(token))
                {
                    cout<< "Keyword : "<< token<<endl;
                }
                else if (isOperator(token))
                {
                    cout<< "Operator : " <<token<<endl;
                }
                else if (isIdentifier(token))
                {
                    cout << "Identifier: " << token << endl;
                }
            }
        }

        MyReadFile.close();
    }

    else
    {
        cout<< "Unable to read file"<<endl;
        return 1;
    }
return 0;

}





