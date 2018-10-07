#include<iostream>
#include<unistd.h> // for sleep(1)

/* how to
 *
 *
 *
 * */

char wenchen[] =
"_/         _/          _/   _/_/_/_/_/_/_/       _/          _/              \n"
" _/       _/ _/       _/    _/                  _/ _/      _/                \n"
"  _/     _/   _/     _/     _/                  _/  _/     _/                \n"
"   _/   _/     _/   _/      _/_/_/_/_/_/_/     _/    _/   _/                 \n"
"    _/ _/       _/ _/       _/                 _/     _/  _/                 \n"
"     _/          _/         _/                _/       _/_/                  \n"
"     _/          _/         _/_/_/_/_/_/_/    _/        _/                   \n";

int main(){
    freopen("output_fancy.txt", "w",  stdout); // this is terminal output
    /*
     * test of terminal codes
    printf("\e[1;1H%s", wenchen);
    fflush(stdout);

    std::string processBar[] {
        "00%: [                     ]",
        "05%: [#                    ]",
        "10%: [##                   ]",
        "15%: [###                  ]",
        "20%: [####                 ]",
        "25%: [#####                ]",
        "30%: [######               ]",
        "35%: [#######              ]",
        "40%: [########             ]",
        "45%: [#########            ]",
        "50%: [##########           ]",
        "55%: [###########          ]",
        "60%: [############         ]",
        "65%: [#############        ]",
        "70%: [##############       ]",
        "75%: [###############      ]",
        "80%: [################     ]",
        "85%: [#################    ]",
        "90%: [###################  ]",
        "95%: [#################### ]",
        "100%:[#####################]",
    };

    int n = sizeof(processBar)/ sizeof(*processBar);
    // pretty fanny
    for(int i{0}; i<n; ++i){
        fprintf(stdout, "\e[%d;1H \e[2K \r \a%s", i, processBar[i].c_str());
        fflush(stdout);
        sleep(1);
    }
    */

    /*
    printf("delete me");
    fflush(stdout);
    sleep(1);
    printf("\e[2K \r"); // delete whole line and move cursor to the begining of the line
    fflush(stdout);

    printf("move me");
    fflush(stdout);
    sleep(1);
    printf("\e[2K \r");
    fflush(stdout);

    printf("go me");
    fflush(stdout);
    sleep(1);
    printf("\e[2K \r");
    */
    /*
     * fgetpos and fsetpos is for reading only
    fpos_t pos;
    fgetpos(stdout, &pos);
    printf("somthing\n");
    fflush(stdout);
    fsetpos(stdout, &pos);
    printf("other thing\n");
    fflush(stdout);
    */
    /*
    for(int i{0}; i<10; ++i){
        sleep(1);
        // printf("\r %d%% ", i);
        printf("\r \e[31m progress bar: \e[0m");
        for(int k{0}; k<i; ++k){
            printf("#");
        }
        fflush(stdout);
    }
    */

    freopen("output_fancy.txt", "w", stdout);
    printf("something");
    fflush(stdout);
    printf("\r another thing");
}
