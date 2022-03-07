# 1 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino" 2

MiniCom com;
Analog cds(A0, 0, 100);

void check()
{
    int value = cds.read();
    com.print(1, "Illu: ", value);
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[CDS Test]]");
}
void loop()
{
    com.run();
}
