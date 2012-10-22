#include "tempomarkerdialog.h"
#include "ui_tempomarkerdialog.h"

#include <QCompleter>
#include <QButtonGroup>

#include <powertabdocument/tempomarker.h>

TempoMarkerDialog::TempoMarkerDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::TempoMarkerDialog),
    beatTypes(new QButtonGroup(this)),
    listessoBeatTypes(new QButtonGroup(this))
{
    ui->setupUi(this);

    QStringList descriptions;
    descriptions << "Fast Rock" << "Faster" << "Moderate Rock" << "Moderately"
                 << "Moderately Fast Rock" << "Moderately Slow Funk"
                 << "Moderately Slow Rock" << "Slow Blues" << "Slow Rock"
                 << "Slower" << "Slowly";
    ui->descriptionComboBox->addItems(descriptions);

    // Autocomplete for description choices.
    QCompleter* completer = new QCompleter(descriptions, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->descriptionComboBox->setCompleter(completer);
    ui->descriptionComboBox->clearEditText();

    // Prevent multiple beat types from being selected at once.
    beatTypes->addButton(ui->note2Button, TempoMarker::half);
    beatTypes->addButton(ui->dottedNote2Button, TempoMarker::halfDotted);
    beatTypes->addButton(ui->note4Button, TempoMarker::quarter);
    beatTypes->addButton(ui->dottedNote4Button, TempoMarker::quarterDotted);
    beatTypes->addButton(ui->note8Button, TempoMarker::eighth);
    beatTypes->addButton(ui->dottedNote8Button, TempoMarker::eighthDotted);
    beatTypes->addButton(ui->note16Button, TempoMarker::sixteenth);
    beatTypes->addButton(ui->dottedNote16Button, TempoMarker::sixteenDotted);
    beatTypes->addButton(ui->note32Button, TempoMarker::thirtySecond);
    beatTypes->addButton(ui->dottedNote32Button,
                         TempoMarker::thirtySecondDotted);
    ui->note4Button->setChecked(true);

    // Set the bpm range.
    ui->bpmSpinBox->setMinimum(40);
    ui->bpmSpinBox->setMaximum(300);
    ui->bpmSpinBox->setValue(120);

    // Prevent multiple listesso beat types from being selected at once.
    listessoBeatTypes->addButton(ui->listessoNote2Button, TempoMarker::half);
    listessoBeatTypes->addButton(ui->listessoDottedNote2Button,
                                 TempoMarker::halfDotted);
    listessoBeatTypes->addButton(ui->listessoNote4Button, TempoMarker::quarter);
    listessoBeatTypes->addButton(ui->listessoDottedNote4Button,
                                 TempoMarker::quarterDotted);
    listessoBeatTypes->addButton(ui->listessoNote8Button, TempoMarker::eighth);
    listessoBeatTypes->addButton(ui->listessoDottedNote8Button,
                                 TempoMarker::eighthDotted);
    listessoBeatTypes->addButton(ui->listessoNote16Button,
                                 TempoMarker::sixteenth);
    listessoBeatTypes->addButton(ui->listessoDottedNote16Button,
                                 TempoMarker::sixteenDotted);
    listessoBeatTypes->addButton(ui->listessoNote32Button,
                                 TempoMarker::thirtySecond);
    listessoBeatTypes->addButton(ui->listessoDottedNote32Button,
                                 TempoMarker::thirtySecondDotted);
    ui->listessoNote2Button->setChecked(true);

    ui->descriptionComboBox->setFocus();
}

TempoMarkerDialog::~TempoMarkerDialog()
{
    delete ui;
}