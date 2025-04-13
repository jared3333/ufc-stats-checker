cmake_minimum_required(VERSION 3.29)
project(M1OEP_jaredcollins)

set(CMAKE_CXX_STANDARD 14)

add_executable(M1OEP_jaredcollins main.cpp
        Fight.cpp
        Fighter.cpp
        FemaleFighter.cpp
        MaleFighter.cpp
        Referee.cpp
        PhysicalAttributes.cpp
        FightStats.cpp
        TitleFight.cpp
        NonTitleFight.cpp
        FightRecord.cpp
        WinsBy.cpp
        StrikingStats.cpp
        GrapplingStats.cpp
)