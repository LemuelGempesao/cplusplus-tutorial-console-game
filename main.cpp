#include <iostream>
#include <string>
#include <cctype>


using namespace std;
void gameName();
string chooseLesson();
void basicConcepts(int *score, bool *sFinished);
void conditionals(int *score, bool *isFinished);
void loopings(int *score, bool *isFinished);
void lecture_or_quiz(string lectures[][5], int lectureRowLen, int lectureColLen, string questionAns[0][2], string your_answers[], int qa_Row_Len, int anslength, int *score, bool *isFinished,string lessonName);
void question_And_Answer(string questionAns[][2], string your_answers[], int qa_Row_Len, int anslength, int *score,bool *isFinished);
void show_lectures(string lectures[][5], int lectureRowLen, int lectureColLen,string lessonName);



int main(){
    // MAIN SCORE
    int score=0;

    //TRIES
    bool l1_isFinished=false, l2_isFinished=false, l3_isFinished=false;
    string choice;

    do{
        gameName();

        while(1){
        choice=chooseLesson();

        if(choice=="1"){
            basicConcepts(&score, &l1_isFinished);
            break;
        }

        else if(choice=="2"){
            if(score>=10 && l1_isFinished){
                conditionals(&score, &l2_isFinished );
                break;
            }

            else{
               cout <<"\n\n\t\t\033[33mAttain a perfect score in lesson 1 to access this lesson\033[0m\n\n\t\t";
            }

        }

        else if(choice=="3"){

            if(score>=20  && l2_isFinished){
                loopings(&score, &l3_isFinished);
                break;
            }
            else{
                cout <<"\n\n\t\t\033[33mAttain a perfect score in lesson 2 to access this lesson\033[0m\n\n\t\t";
            }

        }
        else {
            cout<<"\n\t\t\033[31mInvalid Choice\033[0m";
        }
    }

    }while(choice.length()==1|| choice!="1" && choice!="2" && choice!="3");

    return 0;
}


    void basicConcepts(int *score, bool *isFinished ){


        string LessonName="\n\n\n\n\t\t\033[36mLESSON 1:\033[34m\n\n\t\t\033[34mBASIC CONCEPTS\033[0m\n";
        string lectures[][5]= {
            {"\n\n\t\t\033[34mWELCOME TO C++\033[0m \n\n\t\tC++ is one of the most popular programming languages.\n\t\tIt is used to build games, operating system, browsers, and much more.",
            "\n\n\t\t\033[34mOUTPUT\033[0m \n\n\t\tCoders use output all the time to check the computer if its following the given instruction\n\n\t\t\033[34mex:\033[0m\n\n\t\t\033[32mcout\033[0m \033[31m<<\033[0m \"Welcome to c++\"\033[31m;\033[0m\n",
            "\n\n\t\t\033[34mSTATEMENTS\033[0m \n\n\t\tA line of code is called a statement\n\t\tA statement performs a specific task.\n\n\t\tex:\n\t\t\033[32mcout\033[0m <<\"Coding is an art\"; //displays Coding is an art in the console\n",
            "\n\n\t\t\033[34mSEMICOLON\033[0m\n\n\t\tEach statements in c++ ends width a semicolon ;\n\t\tcout<<\"I love C++\" //returns an error due to no semicolon\n",
            "\n\n\t\t\033[34mOutputting a text\033[0m \n\n\t\tWhen printing text outputs you need to enclose the text in double qoutes\n\t\tcout<<\"C++ is super easy\";\n\n\t\tText VS Numbers\n\t\tComputers treat numbers and text differently.\n\t\tNumber dont need qoutes when you want to output them\n\t\tcout<<42; #displays 42 in the console\n"},

            {"\n\n\t\t\033[34mC++ STRUCTURE\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\t\t}",
            "\n\n\t\t\033[34m#include <iostream>\033[0m\n\n\t\tA header file contains functions and commands\n\t\tWe need it to include in our program to use commands such as cin and cout  ",
            "\n\n\t\t\033[34mNamespace\033[0m\033[0m\n\n\t\tusing namespace std;\n\t\tThis tells the program to use std namespace without prefixing each elememt with std::\n\n\t\tcout<<\"HELLO\";\n\n\t\tinstead of\n\n\t\tstd::cout<<\"HELLO\";\n",
            "\n\n\t\t\033[34mMain function\033[0m\033[0m\n\n\t\tint main(){}\n\n\t\tEach c++ program has an entry point, which is a function called main",
            "\n\n\t\t\033[34mCurly Brackets{}\033[0m\033[0m\n\n\t\tIndicates the beginning and end of the function, or so called the function's body.\n"},

            {"\n\n\n\t\t\033[34mVARIABLES\033[0m \n\n\t\tEvery Program works with values\n\t\tA variable lets you store a value by assigning it to a name or identifier\n",
            "\n\n\t\t\033[34mVariable Types\033[0m \n\t\tEach variable  has a type, which defines the type of the value it holds\n\t\tA variable can hold a text value, a number, decimal, character etc.\n\n\t\tex.\t string message; #This creates a variable called message of type string\n\t\t\t int age;\n",
            "\n\n\t\t\033[34mDeclaration\033[0m \n\n\t\tIt refers to the process of announcing the existence of a variable to a compiler without assigning a \n\t\tvalue to it\n\n\t\tex.string name;\n\t\tint age;\n",
            "\n\n\t\t\033[34mInitialization\033[0m \n\n\t\tIs the process of giving an initial value to variable using assignment operator(=)\n\n\t\tex.string name=\"JOHN\";\n\t\tint age=9;\n\t\t--or--\n\t\tstring surname;\n\t\tsurname=\"Stuoustruop\";\n",
            "\n\n\t\t\033[34mNaming Variables\033[0m \n\n\t\tCommon Conventions of naming variables are:\n\n\t\tCase-Sensitivity: This means that lowercase and uppercase are treated as distinct characters\n\t\tex. \"firstname\", \"firstName\" would be considered 2 different identifiers\n"},

            {"\n\t\t\033[34mAllowed Characters:\033[0m Identifiers can consist and must begin with (uppercase or lowercase)\n\t\tor camelCase convention, digits, and underscores\n\n\t\tfirstname, FIRSTNAME, Firstname, _firstName\n\t\tname1, name2\n\t\tname_1, name_2, _name3,\n",
            "\n\t\t\033[34mInvalid Variable Names:\033[0m Identifiers cannot CONTAIN with certain characters:\n\n\t\tSpecial Symbols: @, # ,$, %, ^,* etc.\n",
            "\n\t\t\033[34mReserved Key Words:\033[0m Identifiers cannot be the same as C++ keywords:\n\n\t\tC++ keywords: int, float, char, return etc.\n",
            "\n\t\t\033[34mCan you find the error?\033[0m \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname;\n\t\t}\n",
            "\n\t\t\033[34mCan you find the error?\033[0m \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname; //this line is the error due to wrong case, it should be cout<<firstName;\n\t\t}\n"},


            {"\n\n\n\t\t\033[34mDATA TYPES\033[0m \n\n\t\tC++ Supports many different data types for your variables based on their value.\n\t\tWe will discuss Basic Data Types\n\t\tIntegers, Characters, floats, and Boolean\n",
            "\n\n\t\t\033[34mIntegers\033[0m \n\n\t\t-Used to store numbers with out decimal points\n\t\tExamples: int, short, long, long long\n\n\t\tint myNum=100;\n\n\t\tcout<<myNum; //displays 100\n",
            "\n\n\t\t\033[34mFloating-Points\033[0m \n\n\t\t-Used to store numbers with decimal points\n\t\tExamples: float, double\n\n\t\tfloat myFloat=2.14f;\n\n\t\tcout<<myFloat //dispays 2.14\n",
            "\n\n\t\t\033[34mCharacters\033[0m \n\n\t\t-Used to store single characters\n\t\tExample: char\n\n\t\tchar myGrade='A';\n\n\t\tcout<<myGrade; //displays A\n",
            "\n\n\t\t\033[34mBooleans\033[0m \n\n\t\t-Used to store true(1)or false(0) values\n\t\tExample: bool\n\n\t\tbool am_I_handsome=true;\n\n\t\tcout<<am_I_handsome; //returns 1 which is true\n"},



            {"\n\n\n\t\t\033[34mARITHMETIC OPERATORS\033[0m \n\n\t\t-Used to perform arithmetic operations on numerical values(Addition, Subtraction, \n\t\tMultiplication, Division or Modulus\n",
            "\n\n\t\t\033[34mAddition(+)\033[0m \n\n\t\t-Adds two values together can be applied in integral, floats, and chars\n\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 + num2; //displays 33\n",
            "\n\n\t\t\033[34mSubtraction(-)\033[0m \n\n\t\t-Subtracts the second value from the first\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 - num2; //displays 13\n",
            "\n\n\t\t\033[34mMultiplication(*)\033[0m\033[0m \n\n\t\t-Multiplies two values together\n\n\t\tex.\n\t\tint num1=10;\n\t\tint num2=6;\n\n\t\tcout<<num1*num2; //displays 60\n",
            "\n\n\t\t\033[34mDivision(/)\033[0m \n\n\t\t-Divides the first value by the second\n\n\t\tex.\n\t\tint num1=50;\n\t\tint num2=5;\n\n\t\tcout<<num1/num2; //displays 10\n\n\t\tModulus(%)\n\t\t-Returns the remainder of the division of the first value by the second\n\n\t\ttex.\n\t\tint num1=53;\n\t\tint num2=5;\n\n\t\tcout<<num1%num2; //displays 3\n"},

            {"\n\n\n\t\t\033[34mOPERATOR PRECEDENCE\033[0m \n\n\t\t-Determines the order in which arithmetic operators are evaluated within an arithmetic expression\n\n\t\t-The precedence of C++ follows PEMDAS Rule, which stands for Parenthesis, Exponent, \n\t\tMultiplication and Division and Addition and Subtraction\n",
            "\n\n\t\t\033[34mMultiplication and Division\033[0m \n\n\t\t-They have the same precedence from left to right\n\n\t\tex. int result=10+5*2\n\n\t\tcout<<result; //displays 20 (5 and 2 are evaluated first(5*2=10) then is added to 10,(10+10=20))\n\n\t\tint result=10+8/2\n\n\t\tcout<<result; //dsiplays 14 (8 and 2 are evaluated first(8/2=4) then added to 10, (10+4=14))\n",
            "\n\n\t\t\033[34mModulus\033[0m \n\n\t\t-This operator is also evaluated after multiplication and division\n\n\t\tex. int result=10+5%3\n\n\t\tcout<<result; //displays 12 (5 and 3 are evaluated first(5%3=2) then added to 10,(10+2=12))\n",
            "\n\n\t\t\033[34mAddition and Subtraction\033[0m \n\n\t\t-These Operators have the same precedence and are evaluated left to right\n\n\t\tex. int result=10+5-3\n\n\t\tcout<<result; //displays 12 (10+5=15, 15-3=(12))",
            "\n\n\t\t\033[34mParenthesis\033[0m \n\n\t\t-Used to control the order of the operation.\n\t\tThey override the operator precedence rule.\n\t\tAllowing you to specify which parts should be evaluated together\n\n\t\tint result=(10+5)*2;\n\n\t\tcout<<result; //displays 30 (10+5=15) are evaluated first due to parenthesis, (15*2=30)\n\n\t\tint result=(10-5)*3;\n\n\t\tcout<<result; //displays 15 (10-5=5), (5*3=(15))\n"
            },

        };

        string questionAns[][2]= {
            {"\n\n\t\t\033[36m1. Which statements are true about C++?\033[0m:\n\n\t\tI.C++ is not a programming language\n\t\tII. C++ can be used to build games.\n\t\tIII.C++ is good for operating systems or browsers development\n\n\t\ta. I only\n\t\tb. II and III\n\t\tc. all of the statements: \n\t\t", "b"},
            {"\n\n\t\t\033[36m2. Find the missing structure\033[0m\n\n\t\t#include <_____>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\n\t\t  return 0;\n\n\t\t}\n\n\t\ta.stdio.h\n\t\tb.iostrim\n\t\tc.iostream\n\t\t", "c"},
            {"\n\n\t\t\033[36m3. This Program returns an error why?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t  string programmingLanguage=\"C++\";\n\n\t\t  cout<<programminglanguage;\n\n\t\t  return 0;\n\n\t\t}:\n\n\t\ta.Calling an incorrect Case of Identifier\n\t\tb.data type should be int\n\t\tc.No semicolon\n\t\t", "a"},
            {"\n\n\t\t\033[36m4. Determine if its a valid or invalid identifier\033[0m\n\n\t\tfirst name\n\n\t\ta.valid\n\t\tb.invalid\n\t\tc.hard to tell\n\t\t", "b"},
            {"\n\n\t\t\033[36m5. Guess the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int myGrade=99;\n\n\t\t cout<<\"myGrade\";\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta.99\n\t\tb.error\n\t\tc.myGrade\n\t\t", "c"},
            {"\n\n\t\t\033[36m6. Determine data type suitable for this data.\033[0m\n\n\t\tThe number of days in a year:\n\n\t\ta.int\n\t\tb.float\n\t\tc.string\n\t\t", "a"},
            {"\n\n\t\t\033[36m7. (7-10)Determine the value of the following expression\033[0m\n\n\t\t3+6*7\n\n\t\ta.46\n\t\tb.56\n\t\tc.45\n\t\t", "c"},
            {"\n\n\t\t\033[36m8. 50%30\033[0m\n\n\t\ta.20\n\t\tb.1\n\t\tc.50/30\n\t\t", "a"},
            {"\n\n\t\t\033[36m9. 10*(2+3)\033[0m\n\n\t\ta.23\n\t\tb.50\n\t\tc.15\n\t\t", "b"},
            {"\n\n\t\t\033[36m10. 3*4/6+6\033[0m\n\n\t\ta.1\n\t\tb.8\n\t\tc.6\n\t\t", "b"}
                };


        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER

        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength, score, isFinished, LessonName);


    }


    void conditionals(int *score, bool *isFinished){
        string LessonName="\n\n\n\n\t\t\033[36mLESSON 2:\033[0m\n\n\t\t\033[31mCONDITIONALS\033[0m\n";
        string lectures[][5]= {
            {"\n\n\n\t\t TAKING INPUTS \n\n\t\t-Your program may take user input for an application to process and generate output\n\n\t\t-To take input, use cin>> command\n\n\t\t-We first declare the variable that will hold our input value, then we use cin>>command\n\n\t\tint age;\n\t\tcin>>age; //for example you type 23\n\t\tcout<<age; /displays 23\n",
            "\n\n\t\t Another Example: \n\n\t\tstring name;\n\t\tcout<<\"Enter name \";\n\t\tcin>>name; //lets assume you type Lemuel\n\t\tcout<<\"You entered: \"<<name; //displays You entered Lemuel\n",
            "\n\n\t\t Multiple Inputs \n\n\t\tYou can take multiple inputs throughout your program\n\n\t\tint a, b;\n\t\tcin>>a; //assume you type 3\n\t\tcin>>b; //assume you type 10;\n\t\tcout<< a+b; //displays 13\n",
            "\n\n\t\t Can you guess the output? \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\tstring name;\n\t\tint age;\n\n\t\tcout<<\"Enter name: \";// assume you type Guko\n\t\tcin>>name;\n\n\t\tcout<<\"Enter age: \"; // assume you type 34\n\n\t\tcout<<\"You are \"<<name<<\" \"<<age<<\" years old\";\n\n\t\treturn 0;\n\n\t\t}\n",
            "\n\n\t\t Can you guess the output? \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\tstring name;\n\t\tint age;\n\n\t\tcout<<\"Enter name: \";// assume you type Guko\n\t\tcin>>name;\n\n\t\tcout<<\"Enter age: \"; // assume you type 34\n\n\t\tcout<<\"You are \"<<name<<\" \"<<age<<\" years old\"; //displays \"You are Guko 34 years old\"\n\n\t\treturn 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\t CONDITIONAL STATEMENTS \n\n\t\t-Are used to perform different actions based on different conditions\n\n\t\t",
            "\n\n\t\t IF STATEMENT \n\n\t\t-The if statements allows you to run a specified code if a given condition is true\n\n\t\tHere is the syntax\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}",
            "\n\n\t\t COMPARISON OPERATORS \n\n\t\t-The following are comparison operators may be used to form the conditions\n\n\t\t< -less than\n\n\t\t> -greater than\n\n\t\t!= -not equal to\n\n\t\t== -equal to\n\n\t\t< -less than or equal to\n\n\t\t>= -greater than or equal to\n\n\t\tExamples\n\n\t\tint grade=80;\n\t\tif(grade > 75){\n\n\t\tcout<<\"You pass\"; //displays \"You pass\", since the condition is true, 80 is greater than 75\n\n\t\t}",
            "\n\n\t\t Can you guess the output? \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t cout<<\"Sunday\";\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n",
            "\n\n\t\t Can you guess the output? \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t cout<<\"Sunday\"; //displays \"Sunday\" since day is equals to 7\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\t ELSE STATEMENT \n\n\t\t-You can use the else statement after an if statement\n\t\tIf you want to run a code in case the condition is false\n\n\t\tSyntax:\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}\n\n\t\telse{\n\t\t//code to run\n\t\t}\n",
            "\n\n\t\t Example: \n\n\t\tstring gender = \"male\";\n\n\t\tif(gender==\"male\"){\n\t\tcout<<\"You are a male\";\n\n\t\t}\n\n\t\telse{\n\t\tcout<<\"You are a female\"; //displays \"You are a female\" since if statement returns false\n\t\t}\n\t\t",
            "\n\n\t\t Can you guess the output? \n\n\t\tExample:\n\n\t\tint grade = 60\n\t\tif(grade >= 75{\n\t\t cout<<\"You passed\";\n\t\t}\n\n\t\telse{\n\t\tcout<<\"You failed \";\n\t\t}",
            "\n\n\t\t Can you guess the output? \n\n\t\tExample:\n\n\t\tint grade = 60\n\t\tif(grade >= 75{\n\t\t cout<<\"You passed\";\n\t\t}\n\n\t\telse{\n\t\tcout<<\"You failed \"; //displays \"You failed\" since grade(52) is not greater than or equal to 75\n\t\t}",
            "\n\n\t\t NESTED IF STATEMENTS \n\n\t\t-You can use one if-else statements inside another if or else statement.\n\n\t\tFor Example:\n\n\t\tint age = 24;\n\n\t\tif(age>=65){\n\t\t  cout<<\"SENIOR\";\n\t\t}\n\n\t\telse{\n\t\t  if(age>=18){\n\t\t  cout<<\"ADULT\"; //displays \"ADULT\" since age (24) is greater than or equal to 18\n\t\t  }\n\t\t  else{\n\t\t    cout<<\"CHILD\";\n\t\t  }\n\t\t}"
            },

            {"\n\n\n\t\t ELSE IF STATEMENT \n\n\t\t-Nested if-else statements become hard to read and maintain. \n\t\tThis is why C++ provides the else if statement.\n\n\t\tSyntax:\n\n\t\tif (condition) {\n\t\t  //some code\n\t\t}\n\t\telse if (condition){\n\t\t  //some code\n\t\t}\n\t\telse {\n\t\t  //some other code\n\t\t}\n",
            "\n\n\t\t Here's our previous example, written using else if: \n\n\t\tint age=24\n\n\t\tif(age >= 65) {\n\t\t  cout<<\"SENIOR\";\n\t\t}\n\t\telse if (age >= 18){\n\t\t  cout<<\"ADULT\";\n\t\t}\n\t\telse{\n\t\t  cout<<\"CHILD\";\n\t\t}\n\t\t",
            "\n\n\t\t Can you guess the output? \n\t\tAssume user enters 'B'\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int points;\n\t\t  char category;\n\n\t\t  cout<<\"Enter Category(A, B, C)\";\n\t\t  cin>>category;\n\n\t\t  if (category == 'A'){\n\t\t    points=100;\n\t\t  }\n\n\t\t  else if(category =='B'){\n\t\t    points=70;\n\n\t\t  }\n\n\t\t  else {\n\t\t    points=50;\n\t\t  }\n\n\t\tcout<<points;\n\n\t\t}\n\t\t",
            "\n\n\t\t Can you guess the output? \n\t\tsAssume user enters 'B'\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int points;\n\t\t  char category;\n\n\t\t  cout<<\"Enter Category(A, B, C)\";\n\t\t  cin>>category;\n\n\t\t  if (category == 'A'){\n\t\t    points=100;\n\t\t  }\n\n\t\t  else if(category =='B'){\n\t\t    points=70;\n\n\t\t  }\n\n\t\t  else {\n\t\t    points=50;\n\t\t  }\n\n\t\tcout<<points; //Displays 70\n\n\t\t}\n\t\t",
            "\n\n\t\t LESSON TAKEAWAYS \n\n\t\t-Decision making is easy right?\n\t\tYou can check for a condition using the if statement.\n\t\tIn case the condition of if statement is false, the code in an else if statement can be executed to test for another condition.\n\n\t\tAnd if the all the conditions are false else statement is executed\n\n\t\t"
            },

             {"\n\n\n\t\tSWITCH STATEMENT\n\n\t\t-The switch statement can be used to check for equality against a list of (int and char) values, \n\t\tinstead of multiple else if statements.\n\n\t\tSyntax:\n\n\t\tswitch (expression or variable) {\n\n\t\t  case constant1:\n\t\t    //some code\n\t\t    break;\n\t\t  case constant2:\n\t\t    //some code\n\t\t    break;\n\t\t  //more cases as needed\n\t\t  default:\n\t\t    //some code\n\t\t    break;\n\t\t}\n\n\t\tExample:\n\n\t\tint choice=2;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\"; //displays \"Tea\" since choice matches with this case(2)\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t    default:\n\t\t      cout << \"Empty\"\n\t\t  }\n\t\t",
            "\n\n\t\tBREAK\n\n\t\t-The break statement is used to terminate the switch, when the case is matched.\n\t\t-If you forget to to add a break statement after each case,\n\t\tthe program will execute the code in the next case statement even if the value does not match\n\n\t\tFor example:\n\n\t\tint choice=2;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\";\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t}\n\n\t\t//Displays \"TeaWater\";\n\t\t",
            "\n\n\t\tDEFAULT\n\n\t\t-You might notice that there is a default case at the end of the switch statement.\n\t\tIt is used to run code, when none of the cases match just like how else statement does:\n\n\t\tFor example:\n\n\t\t\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  int choice=4;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\";\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t    default:\n\t\t      cout << \"Empty\"; //displays \"Empty\" since choice(4) have no matching cases\n\t\t  }\n\t\t}\n",
            "\n\n\t\tCan You guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  char grade = 'C';\n\n\t\t  switch(choice) {\n\t\t    case 'A':\n\t\t      cout << \"Excelent\";\n\t\t    case 'B':\n\t\t      cout << \"Good Job\";\n\t\t    case 'C':\n\t\t      cout << \"Not Bad\";\n\t\t    default:\n\t\t      cout << \"Invalid\"\n\t\t  }\n\t\t}\n",
            "\n\n\t\tCan You guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  char grade = 'C';\n\n\t\t  switch(choice) {\n\t\t    case 'A':\n\t\t      cout << \"Excelent\";\n\t\t    case 'B':\n\t\t      cout << \"Good Job\";\n\t\t    case 'C':\n\t\t      cout << \"Not Bad\"; //displays \"Not Bad\" since grade matches this case ('C')\n\t\t    default:\n\t\t      cout << \"Invalid\"\n\t\t  }\n\t\t}\n",
            },

             {"\n\n\n\t\tMULTIPLE CONDITIONS\n\n\t\t-In some scenarios we need to combine multiple conditions.\n\t\t-In C++, you can use logical operators such as '&&' (logical AND), '||' (logical OR), \n\t\tand '!' (logical NOT)to create multiple conditions in if statements, loops, and other structures\n\n\t\tAND OPERATOR (&&)\n\n\t\t-Used to combine Multiple conditions in such a way that all conditions must be true\n\t\tfor overall expression to be true\n\n\t\tFor example:\n\n\t\tint age=19;\n\n\t\tif (age>=18 && age <=50){\n\t\tcout <<\"Eligible to Work; //displays \"Eligible to Work\" since 19 is within the range of 18 and 50\n\t\t}",
            "\n\n\t\tOR OPERATOR(||)\n\n\t\t-The logical OR operator combines conditions and check if any one of them is true\n\n\t\tFor example:\n\n\t\tint level = 5;\n\t\tint points = 300;\n\n\t\tif (level >=5 || points>=400){\n\t\t  cout << \"You are Allowed to enter this Area\"; //displays this line since one of the condition is true level(5) is >= 5\n\t\t}",
            "\n\n\t\tNOT OPERATOR (!)\n\n\t\t-The logical NOT operator reverse the condition: in case the condition is true,\n\t\tthen not operator will make it false, and vice-e-versa\n\n\t\tFor example:\n\n\t\tint height = 200;\n\n\t\tif(!(height <150){\n\t\t  cout << \'Welcome\"; //displays \"Welcome\" since the condition is inverse from false to true\n\t\t}\n\n\t\t",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; //assume user enters 4\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted\";\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; //assume user enters 4\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted\"; //displays \"Discounted\" since 4 is within the range of this condition\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n"

            }
        };

        string questionAns[][2]= {
            {"\n\n\t\t1. In C++ what command use to take input from the user?\n\n\t\ta. cout\n\t\tb. scanf \n\t\tc. cin\n\t\t", "c"},
            {"\n\n\t\t2. Determine the output\n\n\t\tstring name;\n\n\t\tcout<<\"Enter name \";\n\t\tcin>>name; //lets assume you type BJARNE\n\n\t\tcout<<\"Your name is: \"<<name;\n\n\t\ta. You entered: BJARNE\n\t\tb. Your name is: BJARNE\n\t\tc. You are BJARNE", "b"},
            {"\n\n\t\t3. Supply the missing code\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t __(day==7){\n\t\t cout<<\"Sunday\"; //displays \"Sunday\"\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta. if\n\t\tb. else\n\t\tc. else if", "a"},
            {"\n\n\t\t4. Determine the Output\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int num=8;\n\n\t\t  if(num%2==0){\n\t\t   cout << \"EVEN\";\n\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"ODD\";\n\n\t\t  }\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta. EVEN\n\t\tb. ODD\n\t\tc. 0", "a"},
            {"\n\n\t\t5. Which of the following statements is true about nested if-else statements\n\n\t\ta. They cannot be used in c++\n\t\tb. They can have one if statement and multiple else statement\n\t\tc. They can have multiple if and else statement with each other", "c"},
            {"\n\n\t\t6. What data type is commonly used in switch cases?\n\n\t\ta. int\n\t\tb. floats\n\t\tc. string\n\t\t", "a"},
            {"\n\n\t\t7. Determine the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  int order = 4;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Rice with egg\";\n\t\t    case 2:\n\t\t      cout << \"Rice with ham\";\n\t\t    case 3:\n\t\t      cout << \"Rice with pork\";\n\t\t    default:\n\t\t      cout << \"Water\"\n\t\t  }\n\t\t}\n\n\t\ta. Rice with egg\n\t\tb. Water\n\t\tc. Rice with ham", "b"},
            {"\n\n\t\t8. In C++ what symbol is used for logical OR operator?\n\n\t\ta. &&\n\t\tb. or\n\t\tc. ||", "c"},
            {"\n\n\t\t9. Complete the missing code to run the program\n\n\t\tint day=13;\n\n\t\tif (day>=1 __ day<=12){\n\t\t  cout <<\"Valid Month;\n\n\t\telse{\n\t\t  cout << \"Invalid month\"; //displays \"Invalid month\";\n\t\t}\n\n\t\ta. ||\n\t\tb. !\n\t\tc. &&\n", "c"},
            {"\n\n\t\t10. guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; //assume user enters 5\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free Meal\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted Meal\";\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n\n\t\ta. Free Meal\n\t\tb. Discounted Meal\n\t\tc. Normal\n", "b"}
            };

        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);


        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength, score, isFinished, LessonName);

}


void loopings(int *score, bool *isFinished){

        string LessonName="\n\n\n\n\t\t\033[36mLESSON 3:\033[0m\n\n\t\t\033[35mLOOPINGS\033[0m\n";
        string lectures[][5]={
            {"\n\n\n\t\tLOOPS\n\n\t\t-A loop allows you to repeat a block of code multiple times.\n\t\tFor example, a game can use a loop through all items in the warehouse and perform calculations\n\n\t\t",
            "\n\n\t\tWHLE LOOPS\n\n\t\t-The while loop takes a condition and repeats its statements\n\t\twhile the condition is true.\n\n\t\tSyntax:\n\n\t\twhile(condition) {\n\t\t  //code to be executed repeatedly\n\t\t  //as long as the condition is true\n\t\t}\n",
            "\n\n\t\tFor example:\n\n\t\tint num=1;\n\n\t\twhile(num<5) {\n\t\t cout << num; //displays 1234\n\t\t num=num+1;\n\t\t}\n\t\tThe statement num=num+1 increases the value of num by 1\n\t\teach time the loop runs or so called MODIFIERS.\n\n\t\tThis is important as without it the loop would run forever\n\n\t\t",
            "\n\n\t\tINCREMENT AND DECREMENT\n\n\t\t-As it's common to increment and decrement a value by 1 in loops.\n\t\tC++ provides a special increment and decrement operators.\n\n\t\tvar-- :decreases value of num by 1\n\t\tvar++ :increases value of num by 1\n\n\t\tFor example: (num = num+1 can be num++) or (num = num-1 can be num--)\n\t\t",
            "\n\n\t\tSHORTHAND OPERATORS\n\n\t\t-Sometimes you might need to increase or decrease the value of a variable\n\t\tby a different value than 1.\n\t\tFor these cases C++ provides shorthand operators too!\n\n\t\tFor Example:\n\n\t\tint num = 0;\n\n\t\twhile(num <= 10) {\n\t\t  cout << num << endl;\n\t\t  num+=2;    //shorthand of num = num+2\n\t\t}\n\n\t\t//displays\n\t\t0\n\t\t2\n\t\t4\n\t\t6\n\t\t8\n\t\t10\n\n\t\tSimilarly you can use shorthand for other math operators (*=, /=, %= )\n"
            },


            {"\n\n\t\tCan You guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  while(number >= 0) {\n\n\t\t    cout << number << endl;\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n",
            "\n\n\t\tCan You guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  while(number >= 0) {\n\n\t\t    cout << number << endl;\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n\n\t\t//displays\n\t\t5\n\t\t4\n\t\t3\n\t\t2\n\t\t1\n\t\t0\n",
            "\n\n\t\tDO WHILE\n\n\t\t-Another variation of the while loop is do-while.\n\t\tThe difference with a while loop is that the condition is checked after the code,\n\t\tmeaning the code in the do is executed at least once even if the condition\n\t\tis false\n\n\t\tSyntax:\n\n\t\tdo {\n\n\t\t  //code to be executed\n\t\t  //this code block will execute at least once\n\n\t\t} while (condition);\n\n\t\tFor Example:\n\n\t\tint  num = 0;\n\n\t\tdo{\n\n\t\t  cout << \"Hello \"; //displays Hello Hello Hello\n\t\t  num++;\n\n\t\t} while(num<3);",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \";\n\t\t    num += 2;\n\t\t  }while(num <=5);\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \"; //dipslays 0 2 4\n\t\t    num += 2;\n\t\t  }while(num <=5);\n\t\t}\n"
            },


            {"\n\n\t\tFOR LOOPS\n\n\t\t-A for loop is a control flow statement used to execute a block of code repeatedly\n\t\tbased on a specific condition.\n\n\t\tSyntax:\n\n\t\tfor (initialization; condition; increment/decrement) {\n\t\t  //code to be executed\n\t\t}\n",
            "\n\n\t\tFOR LOOP HEADER\n\n\t\t-The loop header contains 3 components,\n\t\teach serves a specific purpose in controlling the behavior of the loop\n\n\t\tInitialization-Used to initialize a loop control variable, executed only once the loop starts ex. (int i = 0;)\n\n\t\tCondition - A boolean expression that's evaluated before each iteration, if condition is true,\n\t\tloop keeps executing, otherwise, the loop terminates (ex. i < 5;)\n\n\t\tIncrement/Decrement - Used to modify the loop control variable after each iteration. \n\t\tIt's optional and used to update loop control variable ex. (i++, i--, etc)",
            "\n\n\t\tFor Example:\n\n\t\tfor (int i = 1; i<= 5; i++){\n\t\t  cout << i << \" \"; //displays 1 2 3 4 5\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; x--){\n\n\t\t    cout << x <<\" \";\n\n\t\t  }\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; x--){\n\n\t\t    cout << x <<\" \"; //displays 10 9 8 7 6 5 4 3 2 1\n\n\t\t  }\n\t\t}\n"
            },

            {"\n\n\t\tBREAK\n\n\t\t-Remember break; statement that was used in switch to stop when a case\n\t\twas matched? It can also be used to stop a loop\n\n\t\tFor Example:\n\n\t\tfor(int i=0; i<10; i++){\n\t\t  if(i==5) {\n\t\t    break;\n\t\t  }\n\t\t  cout << i <<\" \"; //displays 0 1 2 3 4 5 since break executed when i equals to 5, then the loop terminates\n\t\t}\n",
            "\n\n\t\tCONTINUE\n\n\t\t-The continue statement skips the current loop iteration\n\t\tand continues with the next one\n\n\t\tFor Example:\n\n\t\tfor(int i=0; i<5; i++){\n\t\t  if(i==3) {\n\t\t  cout <<\"Skipping \"<<i<<endl;\n\t\t    continue;\n\t\t  }\n\t\t  cout << i <<endl;\n\n\t\t}\n\n\t\t//displays\n\t\t0\n\t\t1\n\t\t2\n\t\tSkipping 3\n\t\t4\n",
            "\n\n\t\tBREAK AND CONTINUE IN ACTION\n\n\t\tfor(int i=10; i>=0; i--){\n\n\t\t  if(i==7) {\n\t\t    cout <<\"Skipping \"<<i<<endl;\n\t\t    continue;\n\t\t  }\n\n\t\t  if(i==6) {\n\t\t    break;\n\t\t  }\n\n\t\t cout << i <<endl;\n\n\t\t}\n\n\t\t//displays\n\t\t10\n\t\t9\n\t\t8\n\t\tSkipping 7\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=12; x+=2){\n\n\t\t    if(x == 4) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==10) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<endl;\n\n\t\t  }\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=12; x+=2){\n\n\t\t    if(x == 4) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==10) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<endl;\n\n\t\t  }\n\t\t}\n\n\t\t//displays\n\t\t0\n\t\t2\n\t\tskip\n\t\t6\n\t\t8\n"
            }
        };
        string questionAns[][2]= {
                            {"\n\n\t\t\033[36m1. It isa C++ construct that allows you to repeat a block of code multiple times?\033[0m\n\n\t\ta. loop\n\t\tb. conditionals\n\t\tc. variable\n", "a"},
                            {"\n\n\t\t\033[36m2. Supply the missing code\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  ____(number >= 0) {\n\n\t\t    cout << number <<\" \"; //displays 5 4 3 2 1 0\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n\n\t\ta. for\n\t\tb. while\n\t\tc. do\n", "b"},
                            {"\n\n\t\t\033[36m3. What loop construct in C++ guarantees that the loop body is executed at least once,\n\t\teven if the condition is false initially?\033[0m\n\n\t\ta. while loop\n\t\tb. for loop\n\t\tc. do while\n", "c"},
                            {"\n\n\t\t\033[36m4. Determine the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \";\n\t\t    num += 3;\n\t\t  }while(num <=12);\n\t\t}\n\n\t\ta. 0,3,6,9,12\n\t\tb. 0 3 6 9 12\n\t\tc. 036912\n", "b"},
                            {"\n\n\t\t\033[36m5. What loop that contains header loop component (initialization; condition; update)?\033[0m\n\n\t\ta. for loop\n\t\tb. do while\n\t\tc. while\n", "a"},
                            {"\n\n\t\t\033[36m6. Determine the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=12; x>0; x-=4){\n\n\t\t    cout << x <<\" \";\n\n\t\t  }\n\t\t}\n\n\t\ta. 4 8 12\n\t\tb. 8 4\n\t\tc. 12 8 4\n", "c"},
                            {"\n\n\t\t\033[36m7. What statement that can be used to stop a loop\033[0m\n\n\t\ta. break;\n\t\tb. stop;\n\t\tc. endl;\n", "a"},
                            {"\n\n\t\t\033[36m8. What statement that skips the current loop iteration and continues with the next one\033[0m\n\n\t\ta. skip;\n\t\tb. continue;\n\t\tc. next;\n", "b"},
                            {"\n\n\t\t\033[36m9. Supply the missing code\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; ___){\n\n\t\t    cout << x <<\" \"; //displays 10 9 8 7 6 5 4 3 2 1\n\n\t\t  }\n\t\t}\n\t\ta. x+=2\n\t\tb. x++\n\t\tc. x--\n", "c"},
                            {"\n\n\t\t\033[36m10. Determine the Output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=20; x+=4){\n\n\t\t    if(x == 12) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==16) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<\" \";\n\n\t\t  }\n\t\t}\n\n\t\ta. 0 4 8 skip\n\t\tb. 0 4 8 12 skip\n\t\tc. 0 4 8 12 16 20\n", "a"}

            };


        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength, score, isFinished, LessonName);
        string res;
        if(*score==30){
                cout<<"\n\n\n\n\n\n\t\t\033[33mYOU COMPLETED THIS COURSE\033[0m\n\n\t\t      \033[36mCONGRATS!!!!\033[0m\n";
            do{
                cout<<"\n\n\t\t\033[32mPress 1 to exit:\033[0m ";
                cin>>res;
            }while(res!="1");
        }

}


void lecture_or_quiz(string lectures[][5], int lectureRowLen, int lectureColLen, string questionAns[0][2], string your_answers[], int qa_Row_Len, int anslength, int *score, bool *isFinished, string lessonName){

string yes_no;

 do{
            cout<<"\n\n\t\t\033[32mLecture(1) or Quiz(2)?:\033[0m ";
            cin>>yes_no;

            if(yes_no=="1"){
                system("cls");
                show_lectures(lectures, lectureRowLen, lectureColLen, lessonName);

            }

            else if(yes_no=="2"){
                system("cls");
                question_And_Answer(questionAns, your_answers, qa_Row_Len, anslength, score, isFinished);
            }

            else{
                cout<<"\n\n\t\t\033[31mTry again\033[0m\n\n";
            }
        }while(yes_no.length()!=1||(yes_no!="1"&&yes_no!="2"));

}

void question_And_Answer(string questionAns[][2], string your_answers[], int qa_Row_Len, int anslength, int *score, bool *isFinished) {
    int functionScore=0;
    string reset;
    string next;
    for (int i = 0; i < qa_Row_Len; i++) {
        system("cls");
        cout << questionAns[i][0];
        string ans;
        do {
            cout<<"\n\n\t\t\033[36mEnter Answer:\033[0m ";
            cin >> ans;
            ans[0]=tolower(ans[0]);
            if (ans==""|| (ans != "a" && ans != "b" && ans != "c" )) {
                cout << "\n\t\t\033[31mINVALID\033[0m\t\t";
            }
        } while (ans==""|| (ans != "a" && ans != "b" && ans != "c" ));


        your_answers[i] = ans;


        if (your_answers[i]==questionAns[i][1]){
            cout<<"\n\t\t\033[32mCORRECT\033[0m\n";
            functionScore++;
            }

        else{
            cout<<"\n\t\t\033[31mWRONG\033[0m\n\n\t\t\033[36mThe answer is\033[0m:  "<<questionAns[i][1]<<"\n";
            }

        do{
            cout<<"\n\n\n\n\t\t\033[32mPress 1 to proceed\033[0m\n\t\t";
            cin>>next;
            if(next!="1"){
                cout<<"\n\t\t\033[31mTry Again\033[0m\t\t";
            }
        }while(next!="1");
    }
    system("cls");

    cout<<"\n\n\n\n\t\t\033[36mYour Score is: \033[0m"<<"\033[36m"<<functionScore<<"\033[0m"<<"\033[36m/10\033[0m\n\n";
    if(functionScore==10 && !(*isFinished)){
        *score+=functionScore;
        *isFinished=true;
    }

    do{
        cout<<"\n\n\t\t\033[32mPress 1 to exit\033[0m\n\n\t\t";
        cin>>reset;

        if(reset!="1"){
            cout<<"\n\n\t\t\033[31mTry again\033[0m\n\n\t\t";
        }

        else{
            system("cls");
        }

    }while(reset!="1");
}

    //green    \033[32m     \033[0m
    //red      \033[31m
    //blue     \033[34m
    //cyan     \033[36m
    //magenta  \033[35m
    //yellow   \033[33m


void show_lectures(string lectures[][5], int lectureRowLen, int lectureColLen, string lessonName){
    string ans, begins, exits;

    do{cout<<lessonName;
    cout <<"\n\n\n\n\t\t\033[32mPress any key to begin lesson:\033[0m ";
    cin>>begins;
    break;
    }while(1);

    for(int i=0; i<lectureRowLen; i++){
        for(int j=0; j<lectureColLen; j++){
            system("cls");
            cout<<lectures[i][j]<<endl;

            do{
                cout<<"\n\n\t\t\033[32mPress 1 to proceed\n\t\tPress 2 to exit\n\t\t>\033[0m ";
                cin>>ans;
                if(ans!="1" && ans!="2"){
                    cout<<"\n\t\t\033[31mtry again\033[0m\n";
                }

            }while(ans!="1" && ans!="2");

            if(ans=="2"){
                break;
            }
        }
        if (ans=="2"){
            break;
        }
    }


      do{
        system("cls");
        cout<<"\n\n\t\t\033[34mEND OF THE LESSON\033[0m\n\n";
        cout <<"\n\n\n\n\t\t\033[32mPress any key to exit:\033[0m ";
        cin>>exits;
        break;
    }while(1);

}




void gameName(){
    system("cls");


    cout<<"\n\n\t\t\033[36m_____________________________________________________________________\033[0m\n\n"<<endl;
    cout <<"\n\n\t\t\t\t\033[36;46m* * * *\033[0m\t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m     \t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m \t    \033[36;46m* * * * * \033[0m\t    \033[36;46m* * * * * \033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m     \t\t\033[36;46m**\033[0m \t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"\t\t\t\t\033[36;46m* * * *\033[0m\t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;;
    cout<<"\n\n\t\t\t\t\t\033[36mM  O  N  T  A  G  E\033[0m";
    cout<<"\n\n\t\t\033[36m____________________________________________________________________\033[0m\n"<<endl;
    cout << "\n\t\t\t\t  "<<"\033[36mWELCOME TO THE FUNDAMENTALS OF C++\033[0m\n" << endl;

    }



 string chooseLesson(){

    string choice;
    cout<<"\n\n\t\t\033[32mAVAILABLE TOPICS\033[0m: \033[34mBASIC CONCEPTS(1), \033[31mCONDITIONALS(2)\033[0m, \033[35mCONTROL FLOW(3)\033[0m";
    cout<<"\n\n\t\t\033[32mEnter choice(1-3)\033[0m: ";
    cin>>choice;
    return choice;

    }



