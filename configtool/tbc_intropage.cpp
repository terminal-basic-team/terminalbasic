#include "tbc_intropage.hpp"

namespace tbc
{

IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent)
{
    m_widget.setupUi(this);
}

} // namespace tbc
