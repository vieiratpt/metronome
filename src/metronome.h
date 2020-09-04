#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>
#include <QTimer>

class Metronome : public QObject {
    Q_OBJECT

public:
    Metronome(QObject *parent = nullptr);
    ~Metronome() {}

    quint8 beatsPerBar();
    quint8 clicksPerBeat();
    quint8 beatsPerMinute();
    quint8 beat();
    Q_INVOKABLE void setBeatsPerBar(quint8 value);
    Q_INVOKABLE void setClicksPerBeat(quint8 value);
    Q_INVOKABLE void setBeatsPerMinute(quint8 value);
    void setBeat(quint8 value);
    void incrementBeat();
    Q_INVOKABLE void play();
    Q_INVOKABLE void stop();
    void beep();
    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    quint8 _beatsPerBar = 4;
    quint8 _clicksPerBeat = 1;
    quint8 _beatsPerMinute = 100;
    quint8 _beat = 0;
    QTimer *timer = NULL;
};
