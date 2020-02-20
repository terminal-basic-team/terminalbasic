#include "mainwindow.hpp"
#include "tbc_application.hpp"
#include "tbc_intropage.hpp"

#include <QWizard>

int main(int argc, char *argv[])
{
    tbc::Application a(argc, argv);

    QWizard w;
    w.setWindowTitle(QObject::tr(u8"Terminal-BASIC configuration tool"));
    QWizardPage* page = new tbc::IntroPage;
    page->setTitle(QObject::tr(u8"Introduction"));
    page->setSubTitle(QObject::tr(u8"Information about configuration tool"));
    w.addPage(page);

    page = new QWizardPage;
    page->setTitle(QObject::tr(u8"Select the Terminal-BASIC version"));
    page->setSubTitle(QObject::tr(u8"Downloading the source"));
    w.addPage(page);

    page = new QWizardPage;
    page->setTitle(QObject::tr(u8"HAL configuration"));
    page->setSubTitle(QObject::tr(u8"Hardware abstraction level library is the only part, specific to particular hardware/software platform, Terminal-BASIC is ported to"));
    w.addPage(page);

    page = new QWizardPage;
    page->setTitle(QObject::tr(u8"Language configuration"));
    page->setSubTitle(QObject::tr(u8"Select availbale constructs, commands and functions. Try to stay in the platform boundaries."));
    w.addPage(page);

    w.show();

    int res = a.exec();

    return res;
}
