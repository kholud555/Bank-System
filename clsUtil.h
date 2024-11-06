
#pragma once
#include <iostream>
#include <string>
#include"clsString.h"
#include"clsDate.h"
#pragma warning(disable : 4996)
using namespace std;

class clsUtil
{

 public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
       // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
       // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandamCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }
      
        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;

        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 99));
            break;

        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        

        } 


    }

    static string GenerateWord(enCharType key, short length)
    {
        string word = "";
        for (int i = 1; i <= length; i++)
        {
            word = word + GetRandamCharacter(key);
        }
        return word;
    }

   static string Generatekey(enCharType CharType)
    {
        string key = "";
        key = GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4);
        return key;
    }

   static void Generatekeys(enCharType CharType,short Keys_Number)
   {
       for (int i = 1; i <= Keys_Number; i++)
       {
           cout << "key [" << i << "] : " <<
               Generatekey(CharType) << endl;
       }
   }

   static  void Swap(int& A, int& B)
   {
       int Temp;

       Temp = A;
       A = B;
       B = Temp;
   }

   static  void Swap(double& A , double& B)
   {
      double Temp;

       Temp = A;
       A = B;
       B = Temp;
   }

   static  void Swap(string& A, string& B)
   {
       string Temp;

       Temp = A;
       A = B;
       B = Temp;
   }
    
   static  void Swap(clsDate& A, clsDate& B)
   {
       clsDate Temp;

       Temp = A;
       A = B;
       B = Temp;
   }
   
   static void ShuffleArray(int arr[100], int arrlength)
   {
       for (int i = 0; i < arrlength; i++)
       {
           swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
       }
   }

   static void ShuffleArray(string arr[100], int arrlength)
   {
       for (int i = 0; i < arrlength; i++)
       {
           swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
       }
   }

   static void fillArrayWithRandomNumbers(int arr1[100], int arrlength)
   {
       for (int i = 0; i < arrlength; i++)
           arr1[i] = RandomNumber(1, 100);
   }

   static void fillArrayWithRandomWords(string arr[100], int arrlength, enCharType CharType)
   {

       for (int i = 0; i < arrlength; i++)
       {
           arr[i] = GenerateWord(CharType, arrlength);
       }

   }

   static void fillArrayWithRandomKeys(string arr[100], int arrlength, enCharType CharType)
   {
      
       for (int i = 0; i < arrlength; i++)
       {
           arr[i] = Generatekey( CharType);
       }

   }
  
   static string Tabs(int NumOfTabs)
   {
       string Tabs = "";
       for (int i = 0; i < NumOfTabs; i++)
       {
           Tabs = Tabs + "\t";
           cout << Tabs;
       }
       return Tabs;
   }

   static string EncrptionText(string text, const short EncryptionKey = 2)
   {
       for (int i = 0; i <= text.length(); i++)
       {
           text[i] = char((int)text[i] + EncryptionKey);
       } 
       return text;
   } 

   static string DecryptionText(string text, const short EncryptionKey = 2)
   {
       for (int i = 0; i <= text.length(); i++)
       {
           text[i] = char((int)text[i] - EncryptionKey);
       } 
       return text;
   }

   static string NumberToText(int Number)
   {
       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "","one","two","three","four","five","six"
                           ,"seven","eight","nine","ten","eleven","twelve"
                           ,"thirteen","fourteen","fifteen","sixteen","seventeen"
                           ,"eighteen","nineteen" };

           return arr[Number] + " ";
       }
       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","twenty","thirty","fourty","fifty","sixty","seventy"
                         ,"eighty","ninety" };

           return arr[Number / 10] + " " + NumberToText(Number % 10);
       }
       if (Number >= 100 && Number <= 199)
       {
           return "One hundred " + NumberToText(Number % 100);
       }
       if (Number >= 200 && Number <= 999)
       {
           return NumberToText(Number / 100) + "hundreds " + NumberToText(Number % 100);
       }
       if (Number >= 1000 && Number <= 1999)
       {
           return "One thousand " + NumberToText(Number % 1000);
       }
       if (Number >= 200 && Number <= 999999)
       {
           return NumberToText(Number / 1000) + "thousands " + NumberToText(Number % 1000);
       }
       if (Number >= 1000000 && Number <= 1999999)
       {
           return "One Million" + NumberToText(Number % 1000000);
       }
       if (Number >= 2000000 && Number <= 999999999)
       {
           return NumberToText(Number / 1000000) + "Millions" + NumberToText(Number % 1000000);
       }
       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return "One billion" + NumberToText(Number % 1000000000);
       }
       else
       {
           return NumberToText(Number / 1000000000) + "billions" + NumberToText(Number % 1000000000);
       }
   }

};



