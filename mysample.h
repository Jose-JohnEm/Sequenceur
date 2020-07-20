#ifndef MYSAMPLE_H
#define MYSAMPLE_H

#include <QMediaPlayer>

struct asound
{
    QMediaPlayer *sound;
    std::string name;
};

class mySample
{
    public:
        mySample();
        ~mySample();
        void wantoplay(char const *name);
        void wantostop(char const *name);
        void play();
    private:
        asound initSample(char const *name);
        asound findSample(char const *name);
        void removeSample(char const *name, bool permanent = false);
        void removeSample(asound sound, bool permanent = false);

        std::vector<asound> sounds;
        std::vector<asound> waiting_line;

};

#endif // MYSAMPLE_H
