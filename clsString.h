#pragma once
#include <iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;
 
public:

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

	void SetString( string S1)
	{
		_Value = S1;
	}

	string GetString()
	{
		return _Value;
	}

	__declspec(property(get = GetString ,put = SetString )) string value;

    static short Length(string S1)
    {
        return S1.length();
    }

    short Lenght()
    {
        return _Value.length();
    }

   static short CountWords(string S1)
   {
        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

   }

    short CountWords()
    {
        return CountWords(_Value);
    }

    static string UpperFirstletterOfEachWord(string String1)
    {
        bool IsFirstLetter = true;

        for (short i = 0; i <= String1.length(); i++)
        {

            if (String1[i] != ' ' && IsFirstLetter)
            {
                //String1[i]= char(String1[i] - 32);
                String1[i] = toupper(String1[i]);
            }


            IsFirstLetter = (String1[i] == ' ') ? true : false;

        }
        return String1;
    }

    void  UpperFirstletterOfEachWord()
    {
        // no need to return value , this function will directly update the object value
       _Value = UpperFirstletterOfEachWord(_Value);
    }

    static string LowerFirstletterOfEachWord(string String1)
    {
        bool IsFirstLetter = true;

        for (short i = 0; i <= String1.length(); i++)
        {

            if (String1[i] != ' ' && IsFirstLetter)
            {
                //String1[i] = char(String1[i] +32);
                String1[i] = tolower(String1[i]);
            }


            IsFirstLetter = (String1[i] == ' ') ? true : false;

        }
        return String1;
    }

    void LowerFirstletterOfEachWord()
    {
        // no need to return value , this function will directly update the object value
       _Value = LowerFirstletterOfEachWord(_Value);
    }

    static string UpperAllString(string String1)
    {
        for (short i = 0; i <= String1.length(); i++)
        {
            //String1[i] = char(String1[i] +32);
            String1[i] = toupper(String1[i]);
        }


        return String1;
    }

    void UpperAllString()
    {
        // no need to return value , this function will directly update the object value
       _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string String1)
    {
        for (short i = 0; i <= String1.length(); i++)
        {
            //String1[i] = char(String1[i] +32);
            String1[i] = tolower(String1[i]);
        }


        return String1;
    }

    void  LowerAllString()
    {
      _Value = LowerAllString(_Value);
    }

    static char InvertLetterCase(char Ch1)
    {
        return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
    }

    static string InvertAllLettersCase(string S1)
    {
        for (short i = 0; i <= S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }


        return S1;
    }

    void InvertAllLettersCase()
    {
       _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount whatToCount = enWhatToCount::All)
    {
        if (whatToCount == enWhatToCount::All)
            return S1.length();

        short counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (whatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            {
                counter++;
            }

            if (whatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            {
                counter++;
            }
        }


        return counter;

    }

    static short  CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short  CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short CountCharInStringLowerAndUpper(string S1, char Letter, bool MatchCase = true)
    {
        short counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    counter++;

            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                {
                    counter++;
                }
            }
        }



        return counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountCharInStringLowerAndUpper(_Value,Letter , MatchCase);
    }

    static bool IsVowel(char ch1)
    {
        ch1 = tolower(ch1);
        return((ch1 == 'a') || (ch1 == 'o') || (ch1 == 'i') || (ch1 == 'e') || (ch1 == 'u'));
    }
  
    static short  CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string Token; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            Token = S1.substr(0, pos); // store the word   
            // if (sWord != "")
            // {
            vString.push_back(Token);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string delimiter)
    {
        return  Split(_Value, delimiter);
    }

    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {

                return  S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
       _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        char delimiter = ' ';
        short Trim = 0;
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != delimiter)
            {
                Trim = i;

                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
       _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    void Trim()
    {
       _Value = Trim(_Value);
    }

    static string  JoinString(vector<string>Vstring, string delimiter)
    {
        string S1 = "";
        for (string& S : Vstring)
        {
            S1 = S1 + S + delimiter;
        }
        return S1.substr(0, S1.length() - delimiter.length());
    }

    static string  JoinString(string arr[], short length, string delimiter)
    {
        string S1 = "";
        for (short i = 0; i < length; i++)
        {
            S1 = S1 + arr[i] + delimiter;
        }
        return S1.substr(0, S1.length() - delimiter.length());
    }

    static string ReverseWordsInString(string S1)
    {

        vector<string>Vstring;

        string S2 = "";
        Vstring = Split(S1, " ");

        vector<string>::iterator iter = Vstring.end();
        while (iter != Vstring.begin())
        {
            --iter;

            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1);

        return S2;
    }

    void ReverseWordsInString()
    {
       _Value =  ReverseWordsInString(_Value);
    }

    static string ReplacieWords(string S1, string StringToReplace, string RepalceTo, bool MatchCase = true)
    {
        vector<string>Vstring = Split(S1, " ");

        for (string& S : Vstring)
        {
            if (MatchCase)
            {
                if (S == StringToReplace)
                {
                    S = RepalceTo;
                }
            }
            else
            {
                if ((LowerAllString(S)) == (LowerAllString(StringToReplace)))
                {
                    S = RepalceTo;
                }
            }
        }

        return JoinString(Vstring, " ");
    }
   
    string ReplacieWords(string StringToReplace, string RepalceTo)
    {
       return ReplacieWords(_Value, StringToReplace, RepalceTo);
    }

    static string RemovePunctuationsInString(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;
    }

    void RemovePunctuationsInString()
    {
         _Value = RemovePunctuationsInString(_Value);
    }

   static void PrintTheFirstLetter(string String1)
    {
        bool IsFirstLetter = true;

        for (short i = 0; i <= String1.length(); i++)
        {

            if (String1[i] != ' ' && IsFirstLetter)
            {
                cout << String1[i] << endl;

            }
            IsFirstLetter = (String1[i] == ' ') ? true : false;
        }
    }

   void PrintTheFirstLetter()
   {
       PrintTheFirstLetter(_Value);
   }

 static void PrintVowels(string S1)
 {
     short counter = 0;
     cout << "Vowels in string are : ";
     for (short i = 0; i < S1.length(); i++)
     {

         if (IsVowel(S1[i]))
         {
             cout << S1[i] << " ";
         }
     }
     cout << endl;
 }

 void PrintVowels()
 {
     PrintVowels(_Value);
 }

 static void PrintWordsInNewLine(string S1)
 {
     string delim = " ";//delimiter
     cout << "Your string words are :\n";
     short pos = 0;
     string sword;//define a string variable
     //use 
     while ((pos = S1.find(delim)) != std::string::npos)
     {
         sword = S1.substr(0, pos);
         if (sword != "")
         {
             cout << sword << endl;
         }
         S1.erase(0, pos + delim.length());
     }
     if (S1 != "")
     {
         cout << S1 << endl;
     }
 }

 void PrintWordsInNewLine() 
 {
     PrintWordsInNewLine(_Value);
 }

};


