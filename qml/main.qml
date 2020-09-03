import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Metronome 1.0

ApplicationWindow {
    id: window
    title: "Metronome"
    visible: true
    height: 300
    width: 400

    ColumnLayout {
        Label {
            text: "Beats Per Bar"
        }

        Label {
            text: beatsPerMinuteSlider.value
        }
        Slider {
            id: beatsPerMinuteSlider
            from: 20
            to: 250
            value: 100
            onMoved: Metronome.setBeatsPerMinute(value)
        }

        RowLayout {
            id: beatsPerBarSelection
            RadioButton {
                text: "1"
                onClicked: Metronome.setBeatsPerBar(1)
            }

            RadioButton {
                text: "2"
                onClicked: Metronome.setBeatsPerBar(2)
            }

            RadioButton {
                text: "3"
                onClicked: Metronome.setBeatsPerBar(3)
            }

            RadioButton {
                checked: true
                text: "4"
                onClicked: Metronome.setBeatsPerBar(4)
            }
        }

        Label {
            text: "Clicks Per Beat"
        }

        RowLayout {
            id: clicksPerBeatSelection
            RadioButton {
                checked: true
                text: "1"
                onClicked: Metronome.setClicksPerBeat(1)
            }

            RadioButton {
                text: "2"
                onClicked: Metronome.setClicksPerBeat(2)
            }

            RadioButton {
                text: "3"
                onClicked: Metronome.setClicksPerBeat(3)
            }

            RadioButton {
                text: "4"
                onClicked: Metronome.setClicksPerBeat(4)
            }
        }

        Button {
            id: playButton
            text: "PLAY"
        }
    }
}
