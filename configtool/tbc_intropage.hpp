#ifndef TBC_INTROPAGE_HPP
#define TBC_INTROPAGE_HPP

#include <QWizardPage>
#include "ui_intropage.h"

namespace tbc
{

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:

     explicit IntroPage(QWidget* = Q_NULLPTR);

private:

    Ui::IntroPage m_widget;
};

} // namespace tbc

#endif // TBC_INTROPAGE_HPP
