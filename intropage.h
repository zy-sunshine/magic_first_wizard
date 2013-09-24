#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;

class IntroPage : public QWizardPage
{
    public:
        IntroPage( QWidget* parent = 0 );
    private:
        QLabel* label;
};

#endif // INTROPAGE_H
