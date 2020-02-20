#ifndef TBC_APPLICATION_HPP
#define TBC_APPLICATION_HPP

#include <QApplication>

namespace tbc
{

class Application : public QApplication
{
    Q_OBJECT

public:

    Application(int&, char**, int = ApplicationFlags);

private:

    Q_DISABLE_COPY(Application);
};

} // namespace tbc

#endif // TBC_APPLICATION_HPP
