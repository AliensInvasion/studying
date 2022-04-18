#include <iostream>
#include <fstream>
#include <ctime>

struct Character
{
    std::string name = "Unnamed";
    int position = 0;
    int hitPoints = 1;
    int armorPoints = 0;
    int damage = 1;
    bool alive = true;
    bool is_enemy = false;
    char skin = 0;
};

bool intCheck(std::string &str){
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] > '9' || str[i] < '0') return false;
    }
    return true;
}

void fillEmpty(std::string &field){
    for (int i = 1; i < 41; ++i) {
        for (int j = 1; j < 42; ++j) {
            if (j == 41) {
                field += '\n';
                break;
            } else {
                field += '.';
            }
        }
    }
}

void place(std::string &field, Character *characters) {

    for (int i = 0; i < 6; ++i) {
        int randomPoint = (std::rand() % 1638) + 1;
        if (field[randomPoint] == '.') {

            characters[i].position = randomPoint;
            field[randomPoint] = characters[i].skin;

        } else if (i > 0) --i;
    }
}

void show(std::string &field) {
    std::cout << std::endl;
    for (int i = 0; i < 1640; ++i) {
        std::cout << field[i];
    }
    std::cout << std::endl;
}

int intDirection (std::string &direction) {
    if (direction == "left") return 1;
    if (direction == "right") return 2;
    if (direction == "top") return 3;
    if (direction == "bottom") return 4;
    if (direction == "save") return 5;
    if (direction == "load") return 6;
    return 0;
}

int move(Character &character, std::string &field, int &direction) {

    int temp = character.position;
    if (direction == 1) temp -= 1;
    if (direction == 2) temp += 1;
    if (direction == 3) temp -= 41;
    if (direction == 4) temp += 41;

    if (temp < 0 || temp > 1638) return -1;

    if (field[temp] == '.') {
        field[character.position] = '.';
        character.position = temp;
        field[temp] = character.skin;
        return temp;
    }
    if (field[temp] == 'E' && !character.is_enemy) {
        return temp;
    }
    if (field[temp] == 'P' && character.is_enemy) {
        return temp;
    }

    return -1;

}

bool load(Character *characters, std::string &field) {
    std::ifstream save("..\\resources\\save.bin", std::ios::binary);
    if (!save.is_open()) return false;
    for (int i = 0; i < 6; ++i) {
        int nameLength;
        save.read((char*)&nameLength, sizeof(nameLength));
        characters[i].name.resize(nameLength);
        save.read((char*)characters[i].name.c_str(), nameLength);
        save.read((char*)&characters[i].position, sizeof(characters[i].position));
        save.read((char*)&characters[i].hitPoints, sizeof(characters[i].hitPoints));
        save.read((char*)&characters[i].armorPoints, sizeof(characters[i].armorPoints));
        save.read((char*)&characters[i].damage, sizeof(characters[i].damage));
        save.read((char*)&characters[i].alive, sizeof(characters[i].alive));
        save.read((char*)&characters[i].is_enemy, sizeof(characters[i].is_enemy));
        save.read((char*)&characters[i].skin, sizeof(characters[i].skin));
    }
    int fieldLength;
    save.read((char*)&fieldLength, sizeof(fieldLength));
    field.resize(fieldLength);
    save.read((char*)field.c_str(), fieldLength);
    save.close();
    show(field);
    return true;
}

void save(Character *characters, std::string &field) {
    std::ofstream save("..\\resources\\save.bin", std::ios::binary);
    for (int i = 0; i < 6; ++i) {
        int nameLength = characters[i].name.length();
        save.write((char*)&nameLength, sizeof(nameLength));
        save.write(characters[i].name.c_str(), nameLength);
        save.write((char*)&characters[i].position, sizeof(characters[i].position));
        save.write((char*)&characters[i].hitPoints, sizeof(characters[i].hitPoints));
        save.write((char*)&characters[i].armorPoints, sizeof(characters[i].armorPoints));
        save.write((char*)&characters[i].damage, sizeof(characters[i].damage));
        save.write((char*)&characters[i].alive, sizeof(characters[i].alive));
        save.write((char*)&characters[i].is_enemy, sizeof(characters[i].is_enemy));
        save.write((char*)&characters[i].skin, sizeof(characters[i].skin));
    }

    int fieldLength = field.length();
    save.write((char*)&fieldLength, sizeof(fieldLength));
    save.write(field.c_str(), fieldLength);
    save.close();
}

int game(Character *characters, std::string &field) {

    if (!characters[0].alive) return 2;
    std::string str;
    std::cout << "------\n" << characters[0].name << " turn!\n------ \nYour HP = " << characters[0].hitPoints;
    std::cout << ", Your AP = " << characters[0].armorPoints << std::endl;
    std::cout << "Choose a direction(left, right, top, bottom) or save/load:" << std::endl;
    std::cin >> str;
    int direction = intDirection(str);
    while (direction > 4 || direction == 0) {
        if (direction == 5) save(&characters[0], field);
        if (direction == 6) {
            load(&characters[0], field);
            std::cout << "------\n" << characters[0].name << " turn!\n------ \nYour HP = " << characters[0].hitPoints;
            std::cout << ", Your AP = " << characters[0].armorPoints << std::endl;
        }
        std::cout << "Choose a direction(left, right, top, bottom) or save/load:" << std::endl;
        std::cin >> str;
        direction = intDirection(str);
    }

    int position = move(characters[0], field, direction);
    show(field);

    if (characters[0].position != position && position > 0) {
        std::cout << "You attack the enemy!" << std::endl;
        std::cout << "Your damage = " << characters[0].damage << std::endl;
        for (int i = 1; i < 6; ++i) {
            if (characters[i].position == position) {
                std::cout << "Enemy name: " << characters[i].name << std::endl;
                std::cout << "Enemy HP: " << characters[i].hitPoints << std::endl;
                std::cout << "Enemy AP: " << characters[i].armorPoints << std::endl;
                std::cout << "You hit with damage " << characters[0].damage << std::endl;
                if (characters[i].armorPoints - characters[0].damage < 0) {
                    characters[i].hitPoints -= characters[0].damage - characters[i].armorPoints;
                    characters[i].armorPoints = 0;
                    if (characters[i].hitPoints <= 0){
                        characters[i].hitPoints = 0;
                        characters[i].alive = false;
                    }
                } else {
                    characters[i].armorPoints -= characters[0].damage;
                }

                if (!characters[i].alive) {
                    std::cout << "Enemy is dead!" << std::endl;
                    field[characters[i].position] = '.';
                    characters[i].position = -1;

                } else {

                    std::cout << "Enemy HP: " << characters[i].hitPoints << std::endl;
                    std::cout << "Enemy AP: " << characters[i].armorPoints << std::endl;
                }

            }
        }
    }

    bool enemiesDead = true;
    for (int i = 1; i < 6; ++i) {
        if (!characters[i].alive) continue;
        enemiesDead = false;
    }
    if (enemiesDead) return 1;

    std::cout << "\n------\nEnemy turn!\n------" << std::endl;
    for (int i = 1; i < 6; ++i) {
        if (!characters[i].alive) continue;
        direction = std::rand() % 4 + 1;
        position = move(characters[i], field, direction);
        if ((characters[i].position != position) && (position > 0)) {
            std::cout << "Enemy deals " << characters[i].damage << " damage to you!"  << std::endl;
            if (characters[0].armorPoints - characters[i].damage < 0) {
                characters[0].hitPoints -= characters[i].damage - characters[0].armorPoints;
                characters[0].armorPoints = 0;
                if (characters[0].hitPoints <= 0){
                    characters[0].alive = false;
                    break;
                }
            } else {
                characters[0].armorPoints -= characters[i].damage;
            }
        }
    }
    show(field);
    return 0;
}

int main() {

    std::srand(std::time(nullptr));
    std::string field;
    fillEmpty(field);
    Character characters[6];

    std::string answer;
    std::cout << "load?(y/n)" << std::endl;
    std::cin >> answer;

    if (answer != "y") {

        for (int i = 0; i < 6; ++i) {
            if (i == 0) {
                std::string temp;

                std::cout << "Enter player name:" << std::endl;
                std::cin >> characters[i].name;

                std::cout << "Enter hit points number:" << std::endl;
                std::cin >> temp;
                while (!intCheck(temp)) {
                    std::cout << "Enter hit points number:" << std::endl;
                    std::cin >> temp;
                };
                characters[i].hitPoints = std::stoi(temp);
                temp.clear();

                std::cout << "Enter armor points number:" << std::endl;
                std::cin >> temp;
                while (!intCheck(temp)) {
                    std::cout << "Enter armor points number:" << std::endl;
                    std::cin >> temp;
                };
                characters[i].armorPoints = std::stoi(temp);
                temp.clear();

                std::cout << "Enter damage points number:" << std::endl;
                std::cin >> temp;
                while (!intCheck(temp)) {
                    std::cout << "Enter damage points number:" << std::endl;
                    std::cin >> temp;
                };
                characters[i].damage = std::stoi(temp);
                characters[i].skin = 'P';
            } else {
                characters[i].name = "Enemy #" + std::to_string(i);
                characters[i].hitPoints = (std::rand() % 100) + 51;
                characters[i].armorPoints = std::rand() % 51;
                characters[i].damage = (std::rand() % 15) + 16;
                characters[i].is_enemy = true;
                characters[i].skin = 'E';
            }

        }
        place(field, &characters[0]);
        show(field);

    } else if (!load(&characters[0], field)) return 1;


    int result = 0;
    while (result == 0) {
        result = game(&characters[0], field);
    }
    if (result == 1) std::cout << "\n######\nGame over! You won!\n######" << std::endl;
    if (result == 2) std::cout << "\n######\nGame over! You are dead!\n######" << std::endl;

    return 0;

}
