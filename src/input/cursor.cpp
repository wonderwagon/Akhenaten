#include "cursor.h"

#include "building/construction/build_planner.h"
#include "game/system.h"

static const cursor ARROW[] = {
        {
                0, 0, 13, 21,
                "#            "
                "##           "
                "#'#          "
                "#''#         "
                "#'''#        "
                "#''''#       "
                "#'''''#      "
                "#''''''#     "
                "#'''''''#    "
                "#''''''''#   "
                "#'''''''''#  "
                "#''''''''''# "
                "#''''''######"
                "#'''#''#     "
                "#''# #''#    "
                "#'#  #''#    "
                "##    #''#   "
                "#     #''#   "
                "       #''#  "
                "       #''#  "
                "        ##   "
        },
        {
                0, 0, 18, 30,
                "#                 "
                "##                "
                "#&#               "
                "#'&#              "
                "#''&#             "
                "#'''&#            "
                "#''''&#           "
                "#'''''&#          "
                "#''''''&#         "
                "#'''''''&#        "
                "#''''''''&#       "
                "#'''''''''&#      "
                "#''''''''''&#     "
                "#'''''''''''&#    "
                "#''''''''''''&#   "
                "#'''''''''''''&#  "
                "#''''''''''''''&# "
                "#'''''''''''''''$#"
                "#'''''''&#########"
                "#''''$%''$        "
                "#'''$##&'&#       "
                "#''$#  $''%#      "
                "#&#    #&''#      "
                "##      #''%#     "
                "#       #%''#     "
                "         #''&#    "
                "         #%''$    "
                "          #&'&#   "
                "           $'&#   "
                "           ###    "
        },
        {
                0, 0, 24, 40,
                "#                       "
                "##                      "
                "#&#                     "
                "#'&#                    "
                "#''&#                   "
                "#'''&#                  "
                "#''''&#                 "
                "#'''''&#                "
                "#''''''&#               "
                "#'''''''&#              "
                "#''''''''&#             "
                "#'''''''''&#            "
                "#''''''''''&#           "
                "#'''''''''''&#          "
                "#''''''''''''&#         "
                "#'''''''''''''&#        "
                "#''''''''''''''&#       "
                "#'''''''''''''''&#      "
                "#''''''''''''''''&#     "
                "#'''''''''''''''''&#    "
                "#''''''''''''''''''&#   "
                "#'''''''''''''''''''&#  "
                "#''''''''''''''''''''&# "
                "#'''''''''''''''''''''&#"
                "#''''''''''&############"
                "#''''''&&'''$           "
                "#'''''&##'''&#          "
                "#''''&# #%'''%#         "
                "#''''#   #''''#         "
                "#'''#    #%'''%#        "
                "#''#      #&'''#        "
                "#'$#       $'''&#       "
                "#$#        #&'''$       "
                "##          #'''&#      "
                "#           #%'''%#     "
                "             #''''#     "
                "             #%'''%#    "
                "              #&'''#    "
                "               $'&$#    "
                "               ###      "
        }
};

static const cursor SWORD[] = {
        {
                0, 0, 22, 22,
                "#####                 "
                "#'''##                "
                "#''''##               "
                "#'''''##              "
                "##'''''##             "
                " ##'''''##            "
                "  ##'''''##           "
                "   ##'''''##          "
                "    ##'''''##         "
                "     ##'''''##        "
                "      ##'''''##       "
                "       ##'''''##      "
                "        ##'''''#####  "
                "         ##'''''#''#  "
                "          ##'''#'''#  "
                "           ##'#'''##  "
                "            ##'''###  "
                "            #'''##'###"
                "            #''##''''#"
                "            ######'''#"
                "                 #''##"
                "                 #### "
        },
        {
                0, 0, 34, 34,
                "######                            "
                "#%&&&##                           "
                "#&'''&##                          "
                "#&''''&##                         "
                "#&'''''&##                        "
                "##&'''''&##                       "
                " ##&'''''&##                      "
                "  ##&'''''&##                     "
                "   ##&'''''&##                    "
                "    ##&'''''&##                   "
                "     ##&'''''&##                  "
                "      ##&'''''&##                 "
                "       ##&'''''&##                "
                "        ##&'''''&##               "
                "         ##&'''''&##              "
                "          ##&'''''&##             "
                "           ##&'''''&##            "
                "            ##&'''''&##           "
                "             ##&'''''&##          "
                "              ##&'''''&########   "
                "               ##&''''''&##&&$#   "
                "                ##&''''&##&''$#   "
                "                 ##&''&##&''&##   "
                "                  ##%&##&''&###   "
                "                   #&##&''&####   "
                "                   ###&''&#####   "
                "                   ##&''&###%$### "
                "                   #&''&###%'%$$##"
                "                   #&'&###%'''''$#"
                "                   #$$####$%''''$#"
                "                   ########$'''&##"
                "                          #$''&#  "
                "                          ##$$##  "
                "                           ####   "
        },
        {
                0, 0, 46, 44,
                "########                                      "
                "#%%%%%%##                                     "
                "#%'''''&##                                    "
                "#%''''''&##                                   "
                "#%'''''''%##                                  "
                "#%''''''''%##                                 "
                "#%'''''''''%##                                "
                "##%'''''''''%##                               "
                " ##%'''''''''%##                              "
                "  ##%'''''''''%##                             "
                "   ##%'''''''''%##                            "
                "    ##%'''''''''%##                           "
                "     ##%'''''''''%##                          "
                "      ##%'''''''''%##                         "
                "       ##%'''''''''%##                        "
                "        ##%'''''''''%##                       "
                "         ##%'''''''''%##                      "
                "          ##%'''''''''%##                     "
                "           ##%'''''''''%##                    "
                "            ##%'''''''''%##                   "
                "             ##%'''''''''%##                  "
                "              ##%'''''''''%##                 "
                "               ##%'''''''''%##                "
                "                ##%'''''''''%##               "
                "                 ##%'''''''''%##              "
                "                  ##%'''''''''%##########     "
                "                   ##%'''''''''%$$##$$$##     "
                "                    ##%''''''''''%#%'''$#     "
                "                     ##%''''''''%#%''''$#     "
                "                      ##%''''''%#%'''''$#     "
                "                       ##%''''%#%'''''%##     "
                "                        ##%''%#%'''''%###     "
                "                         #$'%#%'''''%####     "
                "                         #$%#%'''''%#####     "
                "                         ###%'''''%###%$#     "
                "                         ##%'''''%###%'$####  "
                "                         #$'''''%###%''%$$$## "
                "                         #$''''%###%'''''''$##"
                "                         #$'''%###%''''''''$##"
                "                         ##$$$####$$%'''''''$#"
                "                         ###########$''''$####"
                "                                   #$'''$&#   "
                "                                    #$''$#    "
                "                                     #####    "
        }
};

static const cursor SHOVEL[] = {
        {
                1, 26, 28, 28,
                "                       ##   "
                "                      ####  "
                "                     ##'### "
                "                     #'''###"
                "                     ##'''##"
                "                    ####'## "
                "                   ##'####  "
                "                  ##'##     "
                "                 ##'##      "
                "                ##'##       "
                "               ##'##        "
                "              ##'##         "
                "             ##'##          "
                "       #    ##'##           "
                "      #### ##'##            "
                "     #''####'##             "
                "    #''''##'##              "
                "   #''''##'##               "
                "  #''''#'#####              "
                " #''''#'''#'##              "
                " #'''#'''#'''##             "
                "#'''''''#''''#              "
                "#''''''#''''#               "
                "#''''''''''#                "
                "#'''''''''#                 "
                "#''''''''#                  "
                " #'''''##                   "
                "  #####                     "
        },
        {
                2, 39, 44, 41,
                "                                   ####     "
                "                                 #######    "
                "                                ##%&#####   "
                "                               ##&''$#####  "
                "                               #$'''''$#### "
                "                               #$''''''$####"
                "                               ##&''''''%## "
                "                              ####&''''$##  "
                "                             ##$''##&&&$#   "
                "                            ##$'''$#####    "
                "                           ##$'''$##        "
                "                          ##$'''$##         "
                "                         ##$'''$##          "
                "                        ##$'''$##           "
                "                       ##$'''$##            "
                "                      ##$'''$##             "
                "                     ##$'''$##              "
                "                    ##$'''$##               "
                "         ###       ##$'''$##                "
                "        ##$##     ##$'''$##                 "
                "       ##%'%##   ##$'''$##                  "
                "      ##%'''%## ##$'''$##                   "
                "     ##%'''''%##%''''$##                    "
                "    ##%''''''%#$''''$##                     "
                "   ##%''''''%#$''''$##                      "
                "  ##%''''''%#$#%''$##                       "
                "  #$''''''%#%'%#$###                        "
                "  #&'''''%#%'''$#%%##                       "
                " ##'''''%#%'''%#%''%##                      "
                " #$''''%#%'''%#%''''%##                     "
                " #&''''%%'''%#%''''''$#                     "
                " #&''''''''%#%''''''%##                     "
                "##''''''''%#%''''''%##                      "
                "#$''''''''%%''''''%##                       "
                "#$'''''''''''''''%##                        "
                "#$''''''''''''''%##                         "
                "#$'''''''''''''%##                          "
                "##'''''''''''&$##                           "
                " #%''''''''&$###                            "
                " ##%&''&%$###                               "
                "  #########                                 "
        },
        {
                3, 52, 58, 55,
                "                                               ##         "
                "                                             ######       "
                "                                            ###&#####     "
                "                                           ##$''&#####    "
                "                                          ##$''''&#####   "
                "                                         ##$'''''''$####  "
                "                                         ##$''''''''$#### "
                "                                         ##$'''''''''$####"
                "                                         ##$''''''''''$###"
                "                                         ###%'''''''''$## "
                "                                        ##%%#%''''''&##   "
                "                                       ##&''%#%''''&##    "
                "                                      ##&''''%#$$$$##     "
                "                                     ##&''''%#######      "
                "                                    ##&''''&###           "
                "                                   ##&''''&##             "
                "                                  ##&''''&##              "
                "                                 ##&''''&##               "
                "                                ##&''''&##                "
                "                               ##&''''&##                 "
                "                              ##&''''&##                  "
                "                             ##&''''&##                   "
                "                            ##&''''&##                    "
                "                           ##&''''&##                     "
                "             ##           ##&''''&##                      "
                "            ####         ##&''''&##                       "
                "           ##%%##       ##&''''&##                        "
                "          ##%''%##     ##&''''&##                         "
                "         ##%''''%##   ##&''''&##                          "
                "        ##%''''''%## ##%''''&##                           "
                "       ##%''''''''%##%'''''&##                            "
                "      ##%'''''''''%#$'''''&##                             "
                "     ##%'''''''''%#%'''''&##                              "
                "    ##%'''''''''%##%''''%##                               "
                "   ##%'''''''''%#%%#%''$##                                "
                "   #$'''''''''%#%''%#%%###                                "
                "   #&''''''''%#%''''%##%%##                               "
                "  ##''''''''%#%'''''%#%''%##                              "
                "  #%'''''''%#%'''''%#%''''%##                             "
                "  #&''''''%#%'''''%#%''''''%##                            "
                "  #''''''&#%'''''%#%''''''''%##                           "
                " #$'''''''&'''''%#%'''''''''%##                           "
                " #%''''''''''''%#%'''''''''%##                            "
                " #&'''''''''''%#%'''''''''%##                             "
                " #&''''''''''&#%'''''''''%##                              "
                " #''''''''''''&'''''''''%##                               "
                " #'''''''''''''''''''''%##                                "
                "##''''''''''''''''''''%##                                 "
                " #'''''''''''''''''''%##                                  "
                " #&'''''''''''''''''%##                                   "
                " #&'''''''''''''''&$##                                    "
                " #$'''''''''''''&$###                                     "
                "  #%'''''''''&%###                                        "
                "   #$%&&&&%$####                                          "
                "    #########                                             "
        }
};

const cursor *input_cursor_data(cursor_shape cursor_id, cursor_scale scale) {
    switch (cursor_id) {
        case CURSOR_ARROW:
            return &ARROW[scale];
        case CURSOR_SHOVEL:
            return &SHOVEL[scale];
        case CURSOR_SWORD:
            return &SWORD[scale];
        default:
            return 0;
    }
}

void input_cursor_update(window_id window) {
    if (window == WINDOW_CITY_MILITARY)
        system_set_cursor(CURSOR_SWORD);
    else if (window == WINDOW_CITY && Planner.build_type == BUILDING_CLEAR_LAND)
        system_set_cursor(CURSOR_SHOVEL);
    else {
        system_set_cursor(CURSOR_ARROW);
    }
}
