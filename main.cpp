#include <QApplication>
#include "textedit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEdit edit;
    edit.setHtml("<html>"
                 "<head>"
                 "    <style>"
                 "        .spoiler {color: gray; background-color: gray;}"
                 "    </style>"
                 "</head>"
                 "<body>"
                 "    <p>"
                 "        Lorem ipsum dolor sit amet consectetur adipisicing elit. Culpa facere error"
                 "        optio, modi, assumenda accusantium tempore hic <span class=\"spoiler\">iure"
                 "        reprehenderit repudiandae</span> molestiae placeat vel consequatur rerum nisi"
                 "        architecto inventore, adipisci ex?"
                 "    </p>"
                 "    <p>"
                 "        Dicta modi accusantium quo molestiae, inventore possimus quaerat explicabo"
                 "        itaque quidem quia minima reprehenderit beatae, <span class=\"spoiler\">"
                 "        architecto quae tempore dolores</span>. Possimus numquam"
                 "        delectus nisi deserunt dolorem rerum voluptatem doloremque! Odit, eos."
                 "    </p>"
                 "    <p>"
                 "        Doloremque, amet totam! <span class=\"spoiler\">Ab tempore possimus"
                 "        accusamus</span> blanditiis accusantium quibusdam assumenda quo iure laborum,"
                 "        minima cupiditate impedit corrupti vero provident aspernatur quod aliquam?"
                 "        Error eius odio aliquid est vel quasi."
                 "    </p>"
                 "</body>"
                 "</html>");
    edit.initSpoilers();
    edit.show();
    return a.exec();
}
