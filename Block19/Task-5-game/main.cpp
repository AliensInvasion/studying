#include <iostream>
#include <fstream>

bool a(std::string &target){

    std::string userAnswer;
    std::string rightAnswer;

    std::cout << std::endl << "Enter the answer:" << std::endl;
    std::cin >> userAnswer;

    std::ifstream answer;
    answer.open("..\\resources\\a" + target + ".txt");
    answer >> rightAnswer;
    answer.close();

    if (userAnswer == rightAnswer) return true;
    else return false;
}

void q(std::string &target) {
    char buffer[10];
    std::ifstream question;
    question.open("..\\resources\\q" + target + ".txt");

    while (!question.eof()) {
        question.read(buffer, sizeof(buffer));
        for (int i = 0; i != question.gcount(); ++i) {
            if (buffer[i] == '\n') std::cout << std::endl;
            else std::cout << buffer[i];
        }
    }
    question.close();
    std::cout << std::endl;
}

bool game(int &questionsPoints, int &answersPoints, int &position, char *sectors) {
    if (questionsPoints == 6) return true;
    if (answersPoints == 6) return false;

    std::cout << "Enter offset:" << std::endl;
    int offset;
    std::cin >> offset;

    for (int i = position, j = 0; j <= offset; ++i, ++j) {

        if (i == 13) i = 0;
        position = i;

        std::cout << "Steps left: " << offset-j << " Current sector = " << position;
        std::cout << ", sector content: " << sectors[position] << std::endl;

        if (sectors[position] == 'x' && j == offset){
            std::cout << "Sector is already used. Moving one more step." << std::endl;
            ++offset;
        }

    }

    std::cout << std::endl;

    std::string target(1, sectors[position]);
    sectors[position] = 'x';

    q(target);
    if (a(target)) ++questionsPoints;
    else ++answersPoints;

    std::cout << questionsPoints << " : " << answersPoints << std::endl;

    game(questionsPoints, answersPoints, position, sectors);

}

int main() {

    char sectors[13] = {97,98,99,100,101,102,103,104,105,106,107,108,109};

    int questionsPoints = 0, answersPoints = 0, position = 0;

    if (game(questionsPoints, answersPoints, position, sectors)) {
        std::cout << "questions won!";
    }
    else std::cout << "answers won!";

    return 0;
}
