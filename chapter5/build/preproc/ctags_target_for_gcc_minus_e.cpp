# 1 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino" 2

MiniCom com;
Ultra ultra(5, 6);
void notice_in()
{
    com.print(1, "NOTICE IN");
}

void notice_out()
{
    com.print(1, "NOTICE OUT");
}

// void check()
// {
// }

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    ultra.setThreshold(40, notice_in, notice_out);
}
void loop()
{
    com.run();
    ultra.run();
}
