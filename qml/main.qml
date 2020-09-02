import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import QtMultimedia 5.8

ApplicationWindow {
    id: window
    title: "Metronome"
    visible: true
    height: 400
    width: 600

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        width: 200
        height: 100
        color: "red"

        Text {
            anchors.centerIn: parent
            text: "Hello, World!"
        }
    }
}
