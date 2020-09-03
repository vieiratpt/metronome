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
    Q_INVOKABLE void setBeatsPerBar(int value);
    Q_INVOKABLE void setClicksPerBeat(int value);
    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    int _beatsPerBar;
    int _clicksPerBeat;
};
