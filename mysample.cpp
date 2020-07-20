#include "mysample.h"

bool isanum_at_end(std::string str)
{
    if (str[str.size() - 1] == '0' ||
        str[str.size() - 1] == '1' ||
        str[str.size() - 1] == '2' ||
        str[str.size() - 1] == '3' ||
        str[str.size() - 1] == '4' ||
        str[str.size() - 1] == '5' ||
        str[str.size() - 1] == '6' ||
        str[str.size() - 1] == '7' ||
        str[str.size() - 1] == '8' ||
        str[str.size() - 1] == '9')
        return true;
    return false;
}

asound mySample::initSample(char const *name)
{
    asound next;
    QString path{"qrc:/samples/music_sample/"};
    next.sound = new QMediaPlayer;

    path.append(name);
    path.append(".mp3");
    next.sound->setMedia(QUrl(path));
    next.name = name;
    return next;
}


asound mySample::findSample(char const *current)
{
    for (size_t i{0}; i < sounds.size(); i++) {
        if (sounds[i].name.find(current) != (size_t)-1)
            return sounds[i];
    }
}

void mySample::removeSample(char const *current, bool permanent)
{
    std::vector<asound> *tmp;

    if (permanent)
        tmp = &sounds;
    else
        tmp = &waiting_line;

    for (size_t i{0}; i < tmp->size(); i++) {
        if ((*tmp)[i].name.find(current) != (size_t)-1)
            tmp->erase(tmp->begin() + i);
    }
}

void mySample::removeSample(asound sound, bool permanent)
{
    std::vector<asound> *tmp;

    if (permanent)
        tmp = &sounds;
    else
        tmp = &waiting_line;

    for (size_t i{0}; i < tmp->size(); i++) {
        if ((*tmp)[i].name.find(sound.name) != (size_t)-1)
            tmp->erase(tmp->begin() + i);
    }
}

void mySample::wantoplay(char const *name)
{
    std::string cuted;

    if (waiting_line.size() == 0) {
        waiting_line.push_back(findSample(name));
        return;
    }

    if (isanum_at_end(name)) {
        cuted = name;
        cuted.pop_back();
        for (size_t i{0}; i < waiting_line.size(); i++) {
            if (waiting_line[i].name.find(cuted) != (size_t)-1)
                removeSample(waiting_line[i]);
        }
    }

    for (size_t i{0}; i < sounds.size(); i++) {
        if (sounds[i].name.find(name) != (size_t)-1)
            waiting_line.push_back(sounds[i]);
    }
}

void mySample::wantostop(char const *name)
{
    for (size_t i{0}; i < waiting_line.size() - 1; i++) {
        if (waiting_line[i].name.find(name) != (size_t)-1)
            removeSample(waiting_line[i]);
    }
}

void mySample::play()
{
    if (waiting_line.size() == 0)
        return;
    for (size_t i{0}; i < waiting_line.size(); i++) {
        waiting_line[i].sound->stop();
        waiting_line[i].sound->play();
    }
}

mySample::mySample()
{
    sounds.push_back(initSample("aguitar1"));
    sounds.push_back(initSample("aguitar2"));
    sounds.push_back(initSample("aguitar3"));
    sounds.push_back(initSample("apiano"));
    sounds.push_back(initSample("bass1"));
    sounds.push_back(initSample("bass2"));
    sounds.push_back(initSample("bass3"));
    sounds.push_back(initSample("bass4"));
    sounds.push_back(initSample("bass5"));
    sounds.push_back(initSample("bass6"));
    sounds.push_back(initSample("choirs"));
    sounds.push_back(initSample("clap1"));
    sounds.push_back(initSample("clap2"));
    sounds.push_back(initSample("clap3"));
    sounds.push_back(initSample("epiano"));
    sounds.push_back(initSample("hithat"));
    sounds.push_back(initSample("kick1"));
    sounds.push_back(initSample("kick2"));
    sounds.push_back(initSample("kick3"));
    sounds.push_back(initSample("sguitar1"));
    sounds.push_back(initSample("sguitar2"));
    sounds.push_back(initSample("shakers"));
    sounds.push_back(initSample("tom"));
}

mySample::~mySample()
{
    removeSample("aguitar1", true);
    removeSample("aguitar2", true);
    removeSample("aguitar3", true);
    removeSample("apiano", true);
    removeSample("bass1", true);
    removeSample("bass2", true);
    removeSample("bass3", true);
    removeSample("bass4", true);
    removeSample("bass5", true);
    removeSample("bass6", true);
    removeSample("choirs", true);
    removeSample("clap1", true);
    removeSample("clap2", true);
    removeSample("clap3", true);
    removeSample("epiano", true);
    removeSample("hithat", true);
    removeSample("kick1", true);
    removeSample("kick2", true);
    removeSample("kick3", true);
    removeSample("sguitar1", true);
    removeSample("sguitar2", true);
    removeSample("shakers", true);
    removeSample("tom", true);
}
