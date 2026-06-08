// MathGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 }; 

enum enPassOrFail {PASS = 1 , FAIL = 2};

struct stQuiz
{
    int HowManyQuestions = 0;
    short FirstNumber = 0;
    short SecondNumber = 0;
    short UserAnswer = 0; 
    short Asnwer = 0;
    bool RightOrWorng=1;
    enQuestionsLevel QestionsLevel;
    enOperationType OpType;
    char OpTypeChar = ' ';
    string AnswerName = "";
};

struct stQuizResults
{
    int NumberOfQesution = 0;
    int NumberOfRightAnswers = 0;
    int NumberOfWrongAnswers = 0;
    enPassOrFail FinalResult;
    enQuestionsLevel QuestionLevel;
    string  FinalResultsName = "";
    string OpTypeName = "";
    string QuestionLevelName = "";
    
};

int ReadHowManyQustions()
{
    int NumberOfQuestion;
    cout << "How many Questions do you want answer? ";
    cin >> NumberOfQuestion;

    return NumberOfQuestion;
}

enQuestionsLevel QuestionsLevel()
{
    int Level = 0;
    do 
    {

        cout << "Enter Questios Level [1]:Easy, [2]: Med, [3]: Hard,[4]: Mix? ";
        cin >> Level;
    } while (Level < 1 || Level > 4);

    return (enQuestionsLevel)Level;
}

enOperationType OperationType()
{
    int OperationType = 0;
    do
    {
        cout << "Enter Operatoin Type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix? ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

int RandomNumber(int from , int to)
{
    int RandomNumber = 0;

    RandomNumber = from + rand() % (to - from + 1);
    return RandomNumber;
}

char GetOperationType(stQuiz Quiz)
{
    char arrOperationType[4] = { '+','-','x','/' };
    if (Quiz.OpType == enOperationType::mix)
    {
        return arrOperationType[RandomNumber(1, 4) - 1];
    }
    return arrOperationType[Quiz.OpType - 1];
}

string GetOperationTypeName(stQuiz Quiz)
{
    string arrOperationTypeName[5] = { "Add","Sub","Mul","Div","Mix" };
    return arrOperationTypeName[Quiz.OpType - 1];
}

int GetRandomNumber(stQuiz Quiz)
{
    switch (Quiz.QestionsLevel)
    {
    case enQuestionsLevel::Easy:
        return RandomNumber(1, 10);
    case enQuestionsLevel::Med:
        return RandomNumber(10, 40);
    case enQuestionsLevel::Hard:
        return RandomNumber(40, 100);
    case enQuestionsLevel::Mix:
        return RandomNumber(1, 100);
            
    }

}

int ReadUserAnswer()
{
    int UserAnswer = 0;
    cin >> UserAnswer;
    return UserAnswer;
}

int GetAnswer(stQuiz Quiz)
{
    switch (Quiz.OpType)
    {
    case enOperationType::Add:
        return Quiz.FirstNumber + Quiz.SecondNumber;
    case enOperationType::Sub:
        return Quiz.FirstNumber - Quiz.SecondNumber;
    case enOperationType::Mul:
        return Quiz.FirstNumber * Quiz.SecondNumber;
    case enOperationType::Div:
        return Quiz.FirstNumber / Quiz.SecondNumber;
    case enOperationType::mix:
        if(Quiz.OpTypeChar=='+')
            return Quiz.FirstNumber + Quiz.SecondNumber;
        else if(Quiz.OpTypeChar == '-')
            return Quiz.FirstNumber - Quiz.SecondNumber;
        else if(Quiz.OpTypeChar == 'x')
            return Quiz.FirstNumber * Quiz.SecondNumber;
        else 
            return Quiz.FirstNumber / Quiz.SecondNumber;

    }
    
}

bool isRightAnswer(stQuiz Quiz)
{
    return (Quiz.UserAnswer == Quiz.Asnwer);
}

string GetAnswerName(bool IsRightAnswer)
{
    if (IsRightAnswer)
        return "Right Answer :-)";
   
    return "Wrong Answer :-(";
}

void SetAnswerSecreen(bool IsPass)
{
    if (IsPass)
        system("color 2F");
    else
    {
        cout << "\a";
        system("color 4F");
    }
}

void PrintQuestionResults(stQuiz Quiz)
{
    cout << Quiz.Asnwer << endl;
    cout << Quiz.AnswerName << endl << endl << endl;

    SetAnswerSecreen(Quiz.RightOrWorng);
}

enPassOrFail IsPass(stQuizResults QuizResults)
{
    if (QuizResults.NumberOfRightAnswers > QuizResults.NumberOfWrongAnswers)
        return enPassOrFail::PASS;
    else
        return enPassOrFail::FAIL;
}

string GetFinalResultsName(enPassOrFail IsPass)
{
    if (IsPass == enPassOrFail::PASS)
        return "PASS :-)";
    else
        return "FAIL :-(";
}

string GetQuestionsLevelName(enQuestionsLevel QuestionLevel)
{
    if (QuestionLevel == enQuestionsLevel::Easy)
        return "Easy";
    else if (QuestionLevel == enQuestionsLevel::Med)
        return "Med";
    else if (QuestionLevel == enQuestionsLevel::Hard)
        return "Hard";
    else
        return "Mix";
}

void PrintFinalQuestionResults(stQuizResults QuizResults)
{ 
    cout << "_______________________\n\n";
    cout << " Final Results is " << QuizResults.FinalResultsName << "\n\n";
    cout << "_______________________\n\n";
    cout << "Number of Questions : " << QuizResults.NumberOfQesution;
    cout << "\nQuestios Level\t: " << QuizResults.QuestionLevelName;
    cout << "\nOpType\t\t: " << QuizResults.OpTypeName;
    cout << "\nNumber of Right Answers : " << QuizResults.NumberOfRightAnswers;
    cout << "\nNumber of Wrong Answers : " << QuizResults.NumberOfWrongAnswers;
    cout << "\n\n______________________";



}

void PrintHalfResutlsOfQuestion(stQuiz Quiz)
{

    cout << Quiz.FirstNumber << endl;
    cout << Quiz.SecondNumber << " " << Quiz.OpTypeChar << endl << endl;
    cout << "___________\n";
}

stQuizResults FillQuizResult(int HowManyQuestions, int RightAnswers, int WrongAnwers,stQuiz Quiz)
{
    stQuizResults QuestionsResults;

    QuestionsResults.NumberOfQesution = HowManyQuestions;
    QuestionsResults.NumberOfRightAnswers = RightAnswers;
    QuestionsResults.NumberOfWrongAnswers = WrongAnwers;
    QuestionsResults.OpTypeName = GetOperationTypeName(Quiz);
    QuestionsResults.QuestionLevel = Quiz.QestionsLevel;
    QuestionsResults.QuestionLevelName = GetQuestionsLevelName(QuestionsResults.QuestionLevel);
    QuestionsResults.FinalResult = IsPass(QuestionsResults);
    QuestionsResults.FinalResultsName = GetFinalResultsName(QuestionsResults.FinalResult);
    
    return QuestionsResults;
}

stQuizResults PlayGame(int HowManayQuestions)
{
    stQuiz Quiz;

    Quiz.HowManyQuestions = HowManayQuestions;
    Quiz.QestionsLevel = QuestionsLevel();
    Quiz.OpType = OperationType();

    short RightAnswres = 0, WrongAnswers = 0; 

    for (int Question = 1; Question <= HowManayQuestions; Question++)
    {
        cout << "\n\nQuestion [" << Question << "/" <<  HowManayQuestions << "]\n\n";
        Quiz.FirstNumber = GetRandomNumber(Quiz);
        Quiz.SecondNumber = GetRandomNumber(Quiz);
        Quiz.OpTypeChar = GetOperationType(Quiz);
        
        PrintHalfResutlsOfQuestion(Quiz);

        Quiz.Asnwer = GetAnswer(Quiz);
        Quiz.UserAnswer = ReadUserAnswer();
        Quiz.RightOrWorng = isRightAnswer(Quiz);
        Quiz.AnswerName = GetAnswerName(Quiz.RightOrWorng);

        if (Quiz.RightOrWorng)
            RightAnswres++;
        else
            WrongAnswers++;

        PrintQuestionResults(Quiz);
    }
    
    return FillQuizResult(HowManayQuestions, RightAnswres, WrongAnswers, Quiz);
}

void ResetSecreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetSecreen();
        stQuizResults QuizResults = PlayGame(ReadHowManyQustions());
        PrintFinalQuestionResults(QuizResults);
        cout << "\n\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    
    return 0;
}

