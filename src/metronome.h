#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>

class Metronome : public QObject {
    Q_OBJECT

public:
    Metronome(QObject *parent = nullptr);
    ~Metronome() {}

    static Metronome* self();

    int beatsPerBar();
    int clicksPerBeat();
    int beatsPerMinute();
    Q_INVOKABLE void setBeatsPerBar(int value);
    Q_INVOKABLE void setClicksPerBeat(int value);
    Q_INVOKABLE void setBeatsPerMinute(int value);
    Q_INVOKABLE void play();
    void beep();
    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    int _beatsPerBar = 4;
    int _clicksPerBeat = 1;
    int _beatsPerMinute = 100;
};
