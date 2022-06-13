#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

class Track
{
    int id = 0;
    std::string name;
    std::tm creationDate{};
    int length = 0;
    //friend class Player;

public:

    Track(int id) {
        std::time_t now = std::time(nullptr);
        std::tm nowInfo = *std::localtime(&now);
        char num = id+49;
        name = "track_";
        name += num;
        creationDate = nowInfo;
        length = (std::rand() % 180) + 1;
    }

    std::string getName() {
        return name;
    }

    int getLength() {
        return length;
    }


};

class Player {

    std::vector<Track> track;
    bool playing = false;
    bool paused = false;

public :

    bool isPlaying() {
        return playing;
    }

    bool isPaused() {
        return paused;
    }

    void stopTrack() {
        if (playing) {
            playing = false;
            std::cout << "Track stopped." << std::endl;
        }
        if (paused) {
            paused = false;
            std::cout << "Track stopped." << std::endl;
        }
    }


    void pauseTrack() {
        if (playing && !paused) {
            playing = false;
            paused = true;
            std::cout << "Track paused." << std::endl;
            return;
        }
        if (!playing && paused) {
            playing = true;
            paused = false;
            std::cout << "Playing..." << std::endl;
            return;
        }
    }

    void playTrack(std::string trackName) {
        if (paused) paused = false;
        for (auto &i : track) {
            if (i.getName() == trackName) {
                std::time_t now = std::time(nullptr);
                std::tm nowInfo = *std::localtime(&now);
                std::cout << "Track name: " << i.getName() << std::endl;
                std::cout << "Creation date: ";
                std::cout << std::put_time(&nowInfo, "%y/%m/%d") << std::endl;
                std::cout << "Length: " << i.getLength() << " seconds";
                std::cout << std::endl;
                std::cout << "Playing..." << std::endl;
                playing = true;
                break;
            }
        }
        if (!playing) {
            std::cout << "No such track!" << std::endl;
        }

    }

    void nextTrack()
    {
        int nextNum = (std::rand() % track.size());
        std::string nextName = track[nextNum].getName();
        playTrack(nextName);
    }

    void listTracks() {
        for (auto &i : track) {
            std::cout << i.getName() << std::endl;
        }
    }

    void initTracks()
    {
        for (int i = 0; i < 3; ++i) {
            Track newTrack(i);
            track.push_back(newTrack);
        }
    }

};

int main() {

    std::srand(std::time(nullptr));
    Player *player = new Player();
    player->initTracks();
    std::string request;

    do {
        std::cout << "Enter request:" << std::endl;
        std::cin >> request;
        if (request == "play") {
            if (!player->isPlaying()) {
                if (!player->isPaused()) {
                    std::cout << "Enter the name of the track: " << std::endl;
                    std::cin >> request;
                    player->playTrack(request);
                }
                else {
                    player->pauseTrack();
                }
            }
        }
        if (request == "pause") {
            player->pauseTrack();
        }
        if (request == "next") {
            player->nextTrack();
        }
        if (request == "list") {
            player->listTracks();
        }
        if (request == "stop") {
            player->stopTrack();
        }

    } while (request != "exit");

    delete player;

    return 0;
}