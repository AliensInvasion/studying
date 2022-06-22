#include <iostream>
#include <ctime>
#define GET_BIG_BRANCH_COUNT (((std::rand() % 3))+3)
#define GET_MIDDLE_BRANCH_COUNT (((std::rand() % 2))+2)

class House {

    std::string name;

public:

    std::string getName()
    {
        return name;
    }

    House(std::string inName) : name(inName) {}

};

class Branch {

    House *house = nullptr;
    Branch *parent = nullptr;
    Branch **children = nullptr;
    int childrenSize = 0;


public:

    House *getHouse()
    {
        return house;
    }

    int getChildrenSize()
    {
        return childrenSize;
    }

    Branch **getChildren()
    {
        return children;
    }

    Branch *getParent()
    {
        return parent;
    }

    void setChildren(int size, Branch **inChildren)
    {
        childrenSize = size;
        children = inChildren;
    }

    void newHouse(std::string name)
    {
        if (name == "null") return;
        house = new House(name);
    }

    void settleElf()
    {
        std::cout << "Parent: " << parent << std::endl;
        std::cout << "House on branch " << this << std::endl;
        std::cout << "Enter the name of the elf:" << std::endl;
        std::string name;
        std::cin >> name;
        /*if (name != "null"){
            name = "";
            name += (std::rand()%10)+48;
            name += (std::rand()%10)+48;
            name += (std::rand()%10)+48;
            name += (std::rand()%10)+48;
        }*/
        std::cout << name << std::endl;
        newHouse(name);
    }

    Branch(Branch *inParent) : parent(inParent) {}

};


class Forest {

    Branch **trees = nullptr;

public:

    int countNeighbours(Branch *branch)
    {
        int count = 0;
        if (branch->getParent()->getParent() == nullptr) {
            for (int i = 0; i < branch->getChildrenSize(); ++i) {
                if (branch->getChildren()[i]->getHouse() != nullptr) ++count;
            }
            return count;
        }

        if (branch->getChildren() == nullptr) {
            if (branch->getParent()->getHouse() != nullptr) ++count;

            for (int i = 0; i < branch->getParent()->getChildrenSize(); ++i) {
                House *house = branch->getParent()->getChildren()[i]->getHouse();
                if (house != nullptr) ++count;
            }
            return count-1;
        }

        return -1;
    }

    Branch *findElf()
    {
        std::string name;
        std::cout << "Find elf:" << std::endl;
        std::cin >> name;

        for (int i = 0; i < 5; ++i) {
            //std::cout << "for i:" << i << std::endl;
            Branch **bigBranches = trees[i]->getChildren();

            for (int j = 0; j < trees[i]->getChildrenSize(); ++j) {
                //std::cout << "\tfor j:" << j << std::endl;
                Branch **midBranches = bigBranches[j]->getChildren();
                if (bigBranches[j]->getHouse()->getName() == name) return bigBranches[j];

                for (int k = 0; k < bigBranches[j]->getChildrenSize(); ++k) {
                    //std::cout << "\t\tfor k:" << k << std::endl;
                    if (midBranches[k]->getHouse()->getName() == name) return midBranches[k];
                }

            }

        }

        return nullptr;
    }

    void settleElves()
    {
        for (int i = 0; i < 5; ++i) {
            //std::cout << "! " << i << std::endl;
            Branch **bigBranches = trees[i]->getChildren();

            for (int j = 0; j < trees[i]->getChildrenSize(); ++j) {
                //std::cout << "\t! " << j << std::endl;
                bigBranches[j]->settleElf();
                Branch **midBranches = bigBranches[j]->getChildren();

                for (int k = 0; k < bigBranches[j]->getChildrenSize(); ++k) {
                    //std::cout << "\t\t! " << k << std::endl;
                    midBranches[k]->settleElf();
                }
            }
        }
    }

    void show()
    {
        for (int i = 0; i < 5; ++i) {
            std::cout << trees[i] << std::endl;
            Branch **treeChildren = trees[i]->getChildren();
            for (int j = 0; j < trees[i]->getChildrenSize(); ++j) {
                std::cout << "\t" << treeChildren[j] << std::endl;
                Branch **bigBranchChildren = treeChildren[j]->getChildren();
                for (int k = 0; k < treeChildren[j]->getChildrenSize(); ++k) {
                    std::cout << "\t\t" << bigBranchChildren[k] << std::endl;
                }
            }
        }
    }

    Forest()
    {
        trees = new Branch*[5];
        for (int i = 0; i < 5; ++i) {

            int bigBranches = GET_BIG_BRANCH_COUNT;
            trees[i] = new Branch(nullptr);
            auto **treeChildren = new Branch*[bigBranches];

            for (int j = 0; j < bigBranches; ++j) {

                int middleBranches = GET_MIDDLE_BRANCH_COUNT;
                auto *bigBranch = new Branch(trees[i]);
                auto **bigBranchChildren = new Branch*[middleBranches];

                for (int k = 0; k < middleBranches; ++k) {
                    auto *midBranch = new Branch(bigBranch);
                    bigBranchChildren[k] = midBranch;
                }

                bigBranch->setChildren(middleBranches, bigBranchChildren);
                treeChildren[j] = bigBranch;
            }

            trees[i]->setChildren(bigBranches, treeChildren);
        }
    }
};

int main() {

    std::srand(std::time(nullptr));

    auto *forest = new Forest();

    forest->show();
    forest->settleElves();

    Branch *elfHouseBranch = nullptr;

    do {
        elfHouseBranch = forest->findElf();
    } while (elfHouseBranch == nullptr);

    std::cout << "Elf found! Branch: " << elfHouseBranch << std::endl;
    std::cout << "Has " << forest->countNeighbours(elfHouseBranch) << " neighbours." << std::endl;

    delete forest;
    forest = nullptr;

}