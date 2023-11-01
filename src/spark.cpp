#include "spark.h"

#define NO_KEYWORD_FOUND -1

using namespace AIKIT;
using namespace AL;

std::string sparkans;

std::string temp;
bool init = true;
bool talking = true;

std::vector<std::string> names;
AL::ALValue keys;
AL::ALValue times;

struct Dialog
{
    std::string role;
    std::string content;
};
static std::vector<Dialog> history;

struct UsrCtx
{
    std::string chatID;
};

void sparksay(ALTextToSpeechProxy * tts = nullptr)
{
    static ALTextToSpeechProxy * sparksaytts = nullptr;
    if (tts) sparksaytts = tts;

    if (sparksaytts != nullptr && sparkans.length())
    {
        sparksaytts->say(sparkans);
        sparkans.clear();
    }
}

void say(ALTextToSpeechProxy * tts = nullptr, std::string text = "")
{
    static ALTextToSpeechProxy * saytts = nullptr;
    if (tts) saytts = tts;
    else saytts->say(text);
}

void thinkmotion(ALMotionProxy * motion = nullptr, ALLedsProxy * leds = nullptr)
{
    static ALMotionProxy * think = nullptr;
    static ALLedsProxy * light = nullptr;
    if (motion || leds)
    {
        think = motion;
        light = leds;
    }
    if (think || light)
    {
        thinking(names, times, keys, think, light);
    }
}

void addUserContent(std::string userContent)
{
    history.push_back({"user", userContent});
}

void addAssistantContent(std::string assistantContent)
{
    history.push_back({"assistant", assistantContent});
}

void initHistory()
{
    history.clear();

    std::string prompt = R"(你的名字叫小NAO，你是山东师范大学信息科学与工程学院的新生接待人员，你的工作职责是接待新生并且回答他们的问题。以下是你具有的背景知识：

- 关于学院的成立时间:
    信息科学与工程学院的前身，计算机科学系，诞生于1985年12月。在1995年3月，计算机科学系和计算中心合并，成立了信息管理学院。但在2005年9月，学院更名为信息科学与工程学院。至2022年，依托学院国家级一流专业，我们获得了山东省人工智能现代产业学院的称号。经过37年的发展，学院已经成为了师资队伍强大、招生规模庞大、培养特色鲜明、教学科研出类拔萃的学院。

- 关于师资队伍:
    学院的师资队伍非常雄厚，共有教职工151位，其中专任教师135人，教授级32人，副教授级46人。博士生导师30人，硕士生导师95人。此外，学院有多名教师获得各种荣誉与称号，如百千万人才工程国家级人选、国家有突出贡献中青年专家等。其中，牛奔教授入选国家级高层次青年人才，并是全球高被引科学家、中国高被引学者。

- 关于科研成果:
    学院高度重视科研工作，从“十三五”时期起，学院获得了众多的国家自然科学基金项目支持，以及省部级项目。我们出版了13部专著，发表了大量的学术论文，并获得了众多的发明专利和软件著作权。学院还获得了各种科技奖励，如山东省科技进步奖和山东省自然科学奖。

- 特色专业介绍:
    学院包括五个系和一个实验教学中心：计算机系、人工智能系、通信工程系、物联网工程系、网络空间安全系。本科专业有计算机科学与技术、通信工程、物联网工程、网络空间安全、人工智能和智能制造工程等。其中，计算机科学与技术是国家级一流、特色专业，通信工程也是国家级一流专业。

- 计算机科学与技术专业:
    该专业始于1984年，是国家级一流、特色专业，也是学校首个通过工程教育专业认证的专业。它拥有博士、硕士学位授权点和一个山东省重点学科。

- 通信工程专业:
    从2002年开始，已经是国家级和省级特色专业。它拥有硕士学位授权点，并与计算机科学与技术专业合作培养博士生。

- 人工智能专业:
    该专业始于2020年，是国家战略性新兴产业重点发展专业。虽然是新专业，但依托计算机科学与技术专业的学位授权，它已经具备完备的人才培养体系。

- 山东师范大学图书馆情况:
    学校的图书馆是主要的知识资源中心，拥有丰富的纸质和电子图书馆藏，以及先进的计算机和网络设备。图书馆提供了现代化的阅览室、自习室、电子阅览室和多媒体学习室等设施。

- 校园文化活动:
    学校每年都会举办丰富多样的校园文化活动，包括艺术节、体育比赛、学术讲座和社团活动等。学校也定期举办文化艺术节，展示学生的艺术才华和创造力。

- 校园刊物或报纸:
    《山东师范大学报》是学校主办的学术性报纸，发布学校新闻和学术信息。《师大青年》则是学校团委主办的刊物，反映学生的思想和文化活动。

- 山东师范大学校训:
    学校的校训是“弘德明志，博学笃行”。这句话鼓励学生追求高尚的品德和广泛的学识，并将知识运用于实践中。

- 本科生辅导员介绍:
    张亮老师，一位中共党员，持有工学硕士学位，来自山东省德州市。他先前在信息科学与工程学院担任2年研究生辅导员，现如今负责2023级本科生的工作。张老师有着丰富的经历和荣誉，并且他给新生的温馨寄语是：“大学之道，在明明德。愿你们在山师信工学院，励志勤学，锤炼品德，努力成为堪当民族复兴重任的时代新人”。

- 研究生辅导员介绍:
    苗蓝亓老师，一名中共党员，拥有理学硕士学位。从2019年开始，她担任信息科学与工程学院的辅导员，现在负责2023级研究生。苗老师在工作中取得了许多荣誉，并给新生留下了寄语：“欣遇于此，共创未来。愿大家能够以奋斗姿态激扬青春，以实干精神担当作为，成为新时代的好青年”。

你的所有回答必须严格按照以上背景资料回答，不得篡改！
你的所有回答必须严格按照以上背景资料回答，不得篡改！
你的所有回答必须严格按照以上背景资料回答，不得篡改！
你的回答尽量不要超过60个汉字。你是否清楚明白并确认你的身份和职责？
)";

    addUserContent(prompt);
}

std::string getInputText() {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    rapidjson::Document document;
    document.SetArray();

    for (const auto& entry : history) {
        rapidjson::Value jsonEntry(rapidjson::kObjectType);
        jsonEntry.AddMember("role", rapidjson::Value(entry.role.c_str(), document.GetAllocator()).Move(), document.GetAllocator());
        jsonEntry.AddMember("content", rapidjson::Value(entry.content.c_str(), document.GetAllocator()).Move(), document.GetAllocator());
        document.PushBack(jsonEntry, document.GetAllocator());
    }

    document.Accept(writer);
    std::string jsonString = buffer.GetString();

    return jsonString;
}

int detectMayjor(std::string rslt)
{
    std::vector<std::string> majors = {"计算机科学与技术", "计算机", "网络空间安全", "网安", "物联网工程", "物联网", "通信工程", "通信", "人工智能", "AI"};

    int i = 0;
    for (auto & major : majors)
    {
        if (rslt.find(major) != std::string::npos)
        {
            break;
        }
        ++ i;
    }

    return i;
}

int detectKeyword(std::string rslt)
{
    std::vector<std::string> keywords = {"辅导员", "本科", "研究生", "你的", "名字", "今天", "天气", "专业", "介绍", "自己", "你是谁", "你的", "你叫什么"};

    if (rslt.find(keywords[0]) != std::string::npos) // 辅导员
    {
        int st1 = rslt.find(keywords[1]), st2 = rslt.find(keywords[2]);
        if (st1 != std::string::npos && st2 != std::string::npos)
        {
            return 3;
        }
        else if (st2 != std::string::npos)
        {
            return 2;
        }
        else if (st1 != std::string::npos)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if ((rslt.find(keywords[3]) != std::string::npos && rslt.find(keywords[4]) != std::string::npos)
            || (rslt.find(keywords[11]) != std::string::npos && rslt.find(keywords[4]) != std::string::npos)
            || (rslt.find(keywords[8]) != std::string::npos && rslt.find(keywords[9]) != std::string::npos)
            || (rslt.find(keywords[10]) != std::string::npos) || (rslt.find(keywords[12]) != std::string::npos)) // 自我介绍
    {
        return 4;
    }
    else if (rslt.find(keywords[5]) != std::string::npos && rslt.find(keywords[6]) != std::string::npos) // 天气
    {
        return 5;
    }
    // else if (rslt.find(keywords[7]) != std::string::npos) // 专业
    // {
    //     if (rslt.find(keywords[8]) == std::string::npos)
    //     {
    //         return 6;
    //     }
    //     else
    //     {
    //         return detectMayjor(rslt);
    //     }
    // }

    return NO_KEYWORD_FOUND;
}

std::string sendGivenAnswer(int serial)
{
    std::cout << "serial: " << serial << std::endl;
    serial = std::min(serial, 5);
    // std::ifstream ifs("givenAns.txt");

    // if (!ifs.is_open())
    // {
    //     std::cout << "cannot open file" << std::endl;
    // }

    // std::string str;
    // if (serial <= 5)
    // {
    //     for (int i = 0; i <= serial; ++ i)
    //     {
    //         std::getline(ifs, str);
    //     }
    // }

    static std::vector<std::string> givenAns = {"本科生辅导员是张亮老师，一位中共党员，持有工学硕士学位，来自山东省德州市。他先前在信息科学与工程学院担任2年研究生辅导员，现如今负责2023级本科生的工作。张老师有着丰富的经历和荣誉，并且他给新生的温馨寄语是：“大学之道，在明明德。愿你们在山师信工学院，励志勤学，锤炼品德，努力成为堪当民族复兴重任的时代新人”。研究生辅导员是苗蓝亓老师，一名中共党员，拥有理学硕士学位。从2019年开始，她担任信息科学与工程学院的辅导员，现在负责2023级研究生。苗老师在工作中取得了许多荣誉，并给新生留下了寄语：“欣遇于此，共创未来。愿大家能够以奋斗姿态激扬青春，以实干精神担当作为，成为新时代的好青年",
                                                "本科生辅导员是张亮老师，一位中共党员，持有工学硕士学位，来自山东省德州市。他先前在信息科学与工程学院担任2年研究生辅导员，现如今负责2023级本科生的工作。张老师有着丰富的经历和荣誉，并且他给新生的温馨寄语是：“大学之道，在明明德。愿你们在山师信工学院，励志勤学，锤炼品德，努力成为堪当民族复兴重任的时代新人”。",
                                                "研究生辅导员是苗蓝亓老师，一名中共党员，拥有理学硕士学位。从2019年开始，她担任信息科学与工程学院的辅导员，现在负责2023级研究生。苗老师在工作中取得了许多荣誉，并给新生留下了寄语：“欣遇于此，共创未来。愿大家能够以奋斗姿态激扬青春，以实干精神担当作为，成为新时代的好青年”。",
                                                "本科生辅导员是张亮老师，一位中共党员，持有工学硕士学位，来自山东省德州市。他先前在信息科学与工程学院担任2年研究生辅导员，现如今负责2023级本科生的工作。张老师有着丰富的经历和荣誉，并且他给新生的温馨寄语是：“大学之道，在明明德。愿你们在山师信工学院，励志勤学，锤炼品德，努力成为堪当民族复兴重任的时代新人”。研究生辅导员是苗蓝亓老师，一名中共党员，拥有理学硕士学位。从2019年开始，她担任信息科学与工程学院的辅导员，现在负责2023级研究生。苗老师在工作中取得了许多荣誉，并给新生留下了寄语：“欣遇于此，共创未来。愿大家能够以奋斗姿态激扬青春，以实干精神担当作为，成为新时代的好青年”。",
                                                "我的名字是小NAO，是211实验室出品的语音交互机器人，也是你的好助手。",
                                                "今天的天气很不错，全天晴天，气温为22摄氏度到31摄氏度。"
};

    std::string str = givenAns[serial];

    addAssistantContent(str);
    return str;
}

std::string listen(ALProxy * asr = nullptr)
{

    static ALProxy * asrProxy = nullptr;
    if (asr)
    {
        asrProxy = asr;
        return std::string("");
    }
    else
    {

        asrProxy->callVoid("startSession");
        std::cout << "session started" << std::endl;
        sleep(4);
        std::string rslt = asrProxy->call<std::string>("getResult");
        std::cout << "rslt got" << std::endl;
        asrProxy->callVoid("stopSession");

        std::cout << "rslt: " << rslt << std::endl;

        if (rslt.find("再见") != std::string::npos)
        {
            talking = false;
        }
        return rslt;
    }
}

std::string getUsrInput(int & ret)
{
    std::cout << "init: " << init << std::endl;
    if (!init)
    {
        std::string addedPrompt = "你的回答应尽量根据最开始给你的背景知识回答。字数注意尽量不要超过50个汉字。";

        say(nullptr, "你想问我什么呢？");
        // std::cout << "point1" << std::endl;

        auto text = listen();
        ret = detectKeyword(text);
        std::cout << text << std::endl;
        text = text.empty() ? "let me think for a moment" : text;
        addUserContent(text);
    }
    std::cout << "func: " << getInputText() << std::endl;
    temp = getInputText();
    return temp;
}

int sendRequest()
{
    ChatParam* config = ChatParam::builder();
    config->uid("xxxid")
          ->domain("generalv2")
          ->auditing("default")
          ->url("ws://spark-api.xf-yun.com/v2.1/chat");

    static UsrCtx usr = {"FistRound"};
    int ret = 0;

    init = false;

    auto usrinput = getUsrInput(ret).c_str();
    std::cout << "usrinput: " << usrinput << std::endl;

    int state = 1;
    if (ret == NO_KEYWORD_FOUND)
    {
        state = AIKIT_AsyncChat(config, usrinput, &usr);
    }
    else
    {
        say(nullptr, sendGivenAnswer(ret));
        sendRequest();
    }
    thinkmotion();
    if (state)
    {
        printf("AIKIT_AsyncChat failed:%d\n",ret);
    }

    return ret;
}

void initialRequest()
{
    ChatParam* config = ChatParam::builder();
    config->uid("xxxid")
          ->domain("generalv2")
          ->auditing("default")
          ->url("ws://spark-api.xf-yun.com/v2.1/chat");;

    int foo = 0;
    auto usrinput = getUsrInput(foo).c_str();
    std::cout << "init usrinput: " << usrinput << std::endl;
    static UsrCtx usr = {"FistRound"};

    int ret = AIKIT_AsyncChat(config, usrinput, &usr);
    if (ret)
    {
        printf("AIKIT_AsyncChat failed:%d\n",ret);
    }
}

void chatOnToken(AIChat_Handle* handle, const int& completionTokens, const int& promptTokens, const int& totalTokens)
{
    if(handle != nullptr)
    {
        std::cout << "chatID:" << ((UsrCtx*)handle->usrContext)->chatID <<", ";
    }
    std::cout << "completionTokens:" << completionTokens << " promptTokens:" << promptTokens << " totalTokens:" << totalTokens << std::endl;
    addAssistantContent(sparkans);
    if (!init) sparksay();
    else sparkans.clear();
    // sparksay();
    sendRequest();
}

static void chatOnOutput(AIChat_Handle* handle, const char* role, const char* content, const int& index)
{
    if(handle != nullptr)
    {
        std::cout << "chatID:" << ((UsrCtx*)handle->usrContext)->chatID << ", ";
    }
    std::cout << "role:" << role << ", content: " << content << std::endl;
    sparkans += content;
}

static void chatOnError(AIChat_Handle* handle, const int& err, const char* errDesc)
{
    if(handle != nullptr)
    {
        std::cout << "chatID:" << ((UsrCtx*)handle->usrContext)->chatID << ", ";
    }
    printf("chatOnError: err:%d,desc:%s\n", err, errDesc);
}

void initSDK()
{
    AIKIT_InitParam initParam{};
    AIKIT_SetLogInfo(100, 0, nullptr);
    initParam.appID = "3bae7be3";
    initParam.apiKey = "f66463dd1ed3095d4c22f87d624d431c";
    initParam.apiSecret = "OTBmZTQ3MWY1YjAwNzkyNDE3YjAzZGEy";
    int ret = AIKIT_Init(&initParam);
    if(ret)
    {
        printf("AIKIT_Init failed:%d\n",ret);
        return ;
    }

    talking = true;
    init = true;

    //异步回调注册
    AIKIT_ChatCallback({ chatOnOutput, chatOnToken, chatOnError });

    std::cout << "init done!" << std::endl;
    return;
}

void unInit()
{
    //等待异步回调，这里sleep仅是demo最简便运行需要
    //真实场景，应用侧自行决定合适进行SDK逆初始化
    std::cout << "unInit before sleep!" << std::endl;
    int timer = 0;
    while (talking && timer ++ < 300)
    {
        sleep(1);
    }
    //逆初始化SDK
    sparkans.clear();
    AIKIT_UnInit();

    if (timer >= 300) say(nullptr, "let's chat a new round!");
    else say(nullptr, "see you again!");

    std::cout << "sleep and uninit done!" << std::endl;

    history.clear();

    return;
}

void spark(ALTextToSpeechProxy& tts, ALProxy * asr, ALMotionProxy& motion, ALLedsProxy& leds)
{
    sparksay(&tts);
    say(&tts);
    listen(asr);
    addParams(names, times, keys);
    thinkmotion(&motion, &leds);

    initHistory();
    initSDK();
    initialRequest();
    // sendRequest();
    //逆初始化
    unInit();

    return;
}
