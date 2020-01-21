#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <bitset>
#include <fstream>
#include "C:\Users\Maverick\Documents\trackdata_to_midi\track.h"
#include "testfile.h"
#include <windows.h>
#include "professionaldialog.h"
using namespace std;

int channel_number=1;

int module5(vector<Track> input_score);

std::string bin_to_hex_patch(const std::string &bin);
std::string hex_note_on_cpv(int channel, int pitch, int velocity);
std::string hex_note_off_cp(int channel, int pitch);

  std::string hex_get_midi_header_d10();
  std::string hex_get_time_division_d2();

  std::string hex_get_mtrk_d4();
  std::string hex_get_track_total_bytes_d4(string the_string);
  std::string hex_get_tempo_n_timesig_n_dT_n_track_name_d19();
  std::string hex_get_track_end_sign_d4();

  std::string hex_get_track_total_number_d2(vector<Track> this_track);
  std::string hex_get_variable_dTime(long int pause_time_in_ms);

 string do_midi_stuff(vector<Track> input_score);
 string do_in_track_note_interpret(Track input_track, int current_track_num);
 void finally_write_to_file(string string_to_write);

 //************Functions here*************
 /*
 void saveAs(const char * path_,string string_to_save)
 {
     std::ofstream outputFile(path_, std::ios_base::binary|ios::trunc);
     outputFile.write( string_to_save.c_str() ,5 );
     outputFile.close();
}

 template <typename T>
 size_t writeBE(std::ofstream &file_, T val_)
 {
     size_t size = sizeof(val_);
     val_ = fix<T>(val_);

     file_.write(reinterpret_cast<char*>(&val_),size);

 #ifndef CXXMIDI_QUIET
     if(file_.bad())
         std::cerr << "CxxMidi: file write error" << std::endl;
 #endif

     return size;
 }
 */


 // CPP program to convert string
 // to char array
 #include <iostream>
 #include <string.h>

 using namespace std;




 // driver code
 void make_your_dream_come_true(string input_string)
 {
     std::ofstream datafile("c:\\buildtemp\\takeaway\\may16.mid", std::ios_base::binary | std::ios_base::out);

     char buf[3];
     buf[2] = 0;

     std::stringstream input(input_string);
     input.flags(std::ios_base::hex);
     while (input)
     {
         input >> buf[0] >> buf[1];
         long val = strtol(buf, nullptr, 16);
         datafile << static_cast<unsigned char>(val & 0xff);
     }
     return ;
 }





 //use the original volume number, and give the number of track.
int remark_vol(int vol, int track_num , int the_instrument ){
    //track_num is track number start from 0

    double coe=1.0;
    double coe_inst=1;
    if (track_num == 0 or track_num == 1 or track_num == 2){coe =dy;}

    // remain design
    switch(the_instrument){
    case -1:break;
    case 1: coe_inst=1;
    case 88: case 89: case 90: case 91: coe_inst=1.3;
    }

    int remark_vol = min(int(coe*coe_inst*vol),127);
    return remark_vol;
}

 string GetHexFromBin(string sBinary)
 {
     string rest(""),tmp = "0000";
     int len = sBinary.length()/4;
     int input_nibbles_to_align = 0;
     if (sBinary.length() % 4 == 0){

     }
     else {
         input_nibbles_to_align = ( (sBinary.length() - sBinary.length() % 4 ) / 4 ) +1 ;
         sBinary.insert(sBinary.begin(), unsigned(input_nibbles_to_align)*4 - sBinary.length(), '0');
     }

     for (int i=0;i<sBinary.length();i+=4)
     {
         tmp = sBinary.substr(i,4);
         if (!tmp.compare("0000"))
         {
             rest = rest + "0";
         }
         else if (!tmp.compare("0001"))
         {
             rest = rest + "1";
         }
         else if (!tmp.compare("0010"))
         {
             rest = rest + "2";
         }
         else if (!tmp.compare("0011"))
         {
             rest = rest + "3";
         }
         else if (!tmp.compare("0100"))
         {
             rest = rest + "4";
         }
         else if (!tmp.compare("0101"))
         {
             rest = rest + "5";
         }
         else if (!tmp.compare("0110"))
         {
             rest = rest + "6";
         }
         else if (!tmp.compare("0111"))
         {
             rest = rest + "7";
         }
         else if (!tmp.compare("1000"))
         {
             rest = rest + "8";
         }
         else if (!tmp.compare("1001"))
         {
             rest = rest + "9";
         }
         else if (!tmp.compare("1010"))
         {
             rest = rest + "A";
         }
         else if (!tmp.compare("1011"))
         {
             rest = rest + "B";
         }
         else if (!tmp.compare("1100"))
         {
             rest = rest + "C";
         }
         else if (!tmp.compare("1101"))
         {
             rest = rest + "D";
         }
         else if (!tmp.compare("1110"))
         {
             rest = rest + "E";
         }
         else if (!tmp.compare("1111"))
         {
             rest = rest + "F";
         }
         else
         {
             continue;
         }
     }
     return rest;
 }


 std::string hex_note_on_cpv(int channel, int pitch, int velocity){
     // 1001 CCCC 0PPP PPPP 0VVV VVV
     std::ostringstream temp_string;
     temp_string<<"9"<<std::right << std::setfill('0')<<std::hex<< std::setw(1)<<channel <<std::setw(2)<<std::hex<<pitch <<std::setw(2)<<std::hex<<velocity;
     return temp_string.str();
 }
 std::string hex_note_off_cp(int channel, int pitch){
     // 1000 CCCC 0PPP PPPP 0000 0000
     std::ostringstream temp_string;
     temp_string<<"8"<<std::right << std::setfill('0')<<std::hex<< std::setw(1)<<channel<<std::setw(2)<<std::hex<<pitch<<"00";
     return temp_string.str();
 }
 std::string hex_get_midi_header_d10(){
     std::string return_str("4D546864000000060001");
     return return_str;
 }
  std::string hex_get_time_division_d2(){
      std::string return_str("01F4");
      return return_str;
 }
// tracks below
  std::string hex_get_mtrk_d4() {
      std::string return_str("4D54726B");
      return return_str;
 }
  std::string hex_get_track_total_bytes_d4(string the_string) {
      //note on+note off=1 note here
      std::ostringstream temp_string;
      int total_bytes= 23 + ( the_string.length()/2 ) ;
      temp_string << std::right<<std::setfill('0')<<std::setw(8)<<std::hex<<total_bytes;
      return temp_string.str();
 }
  std::string hex_get_tempo_n_timesig_n_dT_n_track_name_d19() {
      std::string return_str("00FF58040402180800FF510307A12000FF0300");
      return return_str;
 }

  std::string hex_get_track_end_sign_d4() {
      std::string return_str("00FF2F00");
      return return_str;
 }
 // utils below
  std::string hex_get_track_total_number_d2(vector<Track> track_vector){
      int total_track_count = 0;
      std::ostringstream temp_string2;

      for (int track_num = 0 ; unsigned(track_num) < track_vector.size(); track_num ++){
          //need header here!
          if ((track_vector[unsigned(track_num)].i()) != -1){
              total_track_count ++;

          }
          else{
              continue;

          }
      }
      temp_string2<<std::right<<std::setfill('0')<<std::setw(4)<<std::hex<<total_track_count;
      //cout<<temp_string2.str();
      return temp_string2.str();
  }

  std::string hex_get_variable_dTime(long int pause_time_in_ms){


      std::ostringstream temp_string;
      std::ostringstream temp_string2;
      std::string output_string;

      //cout<<pause_time_in_ms<<endl;
      temp_string<<std::bitset<8*sizeof(pause_time_in_ms)>(pause_time_in_ms);

      //trim leading zeros
      output_string = temp_string.str();
      output_string.erase(0, output_string.find_first_not_of('0'));
      if(output_string==""){
          output_string="00000000";
          //cout<<output_string<<"zero"<<endl;

          return GetHexFromBin(output_string);
          //return bin_to_hex_patch(output_string);
      }
      else if(pause_time_in_ms<=127){
          temp_string2<<"0"<<std::right << std::setfill('0') <<std::setw(7)<<output_string;

          //cout<<temp_string2.str()<<"o127"<<endl;

          return GetHexFromBin( temp_string2.str());
      }
      else if(pause_time_in_ms<=16383){
          temp_string2<<"1"<<std::right << std::setfill('0') <<std::setw(14)<<output_string;
          output_string=temp_string2.str();
          output_string.insert(8,"0");
          //cout<<temp_string2.str()<<"16k"<<endl;

          return GetHexFromBin( output_string );

      }
      else if(pause_time_in_ms<=2097151){
          temp_string2<<"1"<<std::right << std::setfill('0') <<std::setw(21)<<output_string;
          output_string=temp_string2.str();
          output_string.insert(8,"1");
          output_string.insert(16,"0");
          //cout<<temp_string2.str()<<"2097k"<<endl;
          return GetHexFromBin( output_string );
      }
      else if(pause_time_in_ms<=268435455){
          temp_string2<<"1"<<std::right << std::setfill('0') <<std::setw(28)<<output_string;
          output_string=temp_string2.str();
          output_string.insert(8,"1");
          output_string.insert(16,"1");
          output_string.insert(24,"0");
          //cout<<temp_string2.str()<<"max"<<endl;
          return GetHexFromBin( output_string );
      }
      //temp_string << std::bitset<28>(pause_time_in_ms);
      //output_string = temp_string.str();
      //cout<<output_string<<endl<<endl;
      //output_string.insert(0,"1");
      //cout<<output_string<<endl<<endl;
      //output_string.insert(8,"1");
      //cout<<output_string<<endl<<endl;
      //output_string.insert(16,"1");
      //cout<<output_string<<endl<<endl;
      //output_string.insert(24,"0");
      //cout<<output_string<<endl<<endl;
  }


  string do_midi_stuff(vector<Track> input_score){
      // return a string to write(in hex, try directly writing into file)
      string write_eventually_from_this;
      string store_this_track_here;

      write_eventually_from_this.append(hex_get_midi_header_d10());
      write_eventually_from_this.append(hex_get_track_total_number_d2(input_score));
      write_eventually_from_this.append(hex_get_time_division_d2());

      for (int track_num = 0 ; unsigned(track_num) <  input_score.size(); track_num ++){
          //need header here!
          if ((input_score[unsigned(track_num)].i()) != -1){
              write_eventually_from_this.append(do_in_track_note_interpret(input_score[unsigned(track_num)],track_num));
          }
          else{
              continue;
          }
      }

      return write_eventually_from_this;
  }

  string do_in_track_note_interpret(Track input_track, int current_track_num){
      // return with track header and end, a track will be provided as parameter
      string L3_cache_string;
      string real_return_string;

      std::ostringstream temp_string;

      char temp_char;

      int track_instrument=0, note_volume=0, note_pitch=0;
      long note_start_time=0, note_end_time=0;
      vector< vector<string> > interpret_cache(300000);
      //vector< vector<string> > interpret_cache(3000);
      //
      /*
       * Sample:
       * track1.seti(0);
       * for (int i = 0; i < track.size(); ++i){
       * vector<int> pitches = track1.n();
       * int startTime = track1.st(pt);
       * int EndTime = track1.et(pt);
       * int vol = track1.vol(tpl);
       * track1.newNote();
       * }
       */

     /*
      * vector<int> pitches = track1.get_pitch();   得到音高的vector
      * int startTime = track1.get_start_time();    得到点起始时间
      * int EndTime = track1.get_end_time();        得到点终止时间
      * int vol = track1.get_volume();              得到点音量，请自行测试调整大小
      * int instrument = track1.get_instrument();   得到乐器，integer对应关系参照gm1
      * ......
      */
      // do a nested vector, vector<vector<int>> variable_name
      //
      //set track seti
      //data: instrument   starttime endtime volume pitch
      //function: .set_index .get_pitch .get_volume .get_start_time .get_end_time .get_instrument .new_note
      // pretend i've done the job above


      track_instrument = input_track.get_instrument();
      //temp_char = input_track.get_instrument();
      //interpret_cache[0].push_back(to_string(track_instrument));
      input_track.seti(0);

      if (track_instrument == -2){
          //if it's percussion
          // throw it to channel 09
          for (int loop_index = 0; loop_index < input_track.size(); ++loop_index){

              //note_volume = input_track.get_volume();
              //note_pitch = input_track.get_pitch();
              note_start_time = input_track.get_start_time();
              note_end_time = input_track.get_end_time();
              int percussion_vol = 80;


              for(int note_index = 0; note_index < input_track.get_pitch().size(); ++note_index){

                  switch(input_track.get_pitch()[note_index]){
                  case 57: percussion_vol =50; break;
                  case 54: percussion_vol =65; break;
                  }
                interpret_cache[note_start_time].push_back(hex_note_on_cpv(9,input_track.get_pitch()[note_index],percussion_vol));
                interpret_cache[note_end_time].push_back(hex_note_off_cp(9,input_track.get_pitch()[note_index]));
              }
              input_track.newNote();

      }
      }
      else {

      for (int loop_index = 0; loop_index < input_track.size(); ++loop_index){

          note_volume = remark_vol( input_track.get_volume(), current_track_num ,track_instrument) ;
          //note_pitch = input_track.get_pitch();
          note_start_time = input_track.get_start_time();
          note_end_time = input_track.get_end_time();


          for(int note_index = 0; note_index < input_track.get_pitch().size(); ++note_index){
            interpret_cache[note_start_time].push_back(hex_note_on_cpv(channel_number,input_track.get_pitch()[note_index],note_volume));
            interpret_cache[note_end_time].push_back(hex_note_off_cp(channel_number,input_track.get_pitch()[note_index]));
          }
          input_track.newNote();
      }
      }
      // Great! cache is set!
      // Now start to prepare MIDI hex!


      if (track_instrument == -2){
          track_instrument = 0;
      }
      temp_string<<"00C"<<std::right << std::setfill('0') <<std::setw(1)<<std::hex<<channel_number<<std::setw(2)<<std::hex<<track_instrument;
      L3_cache_string.append(temp_string.str());
      //program change
      //interpret_cache[0].erase(interpret_cache[0].begin());
      //interpret_cache[0].resize(0);

      //destory that stuff

      long last_note_time = 0;
      for (long current_time = 0; current_time < 300000; ++current_time){
          for (int second_pointer=0; second_pointer < interpret_cache[current_time].size(); ++second_pointer){
              L3_cache_string.append(hex_get_variable_dTime((current_time-last_note_time)));
              last_note_time = current_time;
              L3_cache_string.append(interpret_cache[current_time][second_pointer]);
          }
          /*
          while (interpret_cache[current_time].empty() != true) {
              return_string.append(hex_get_variable_dTime((current_time-last_note_time)));
              last_note_time = current_time;
              return_string.append(interpret_cache[current_time][0]);
              interpret_cache[0].erase(interpret_cache[0].begin());

          }*/
      }
      channel_number += 1;
      if (channel_number==9){
          channel_number+=1;
      }

      real_return_string.append(hex_get_mtrk_d4());
      real_return_string.append(hex_get_track_total_bytes_d4(L3_cache_string));
      real_return_string.append(hex_get_tempo_n_timesig_n_dT_n_track_name_d19());
      real_return_string.append(L3_cache_string);
      real_return_string.append(hex_get_track_end_sign_d4());

      return real_return_string;



  }
  //******************************************

  void finally_write_to_file(string string_to_write){
      ofstream output_file_handle("C:\\buildtemp\\takeaway\\trackdata2midi.mid",ios::out|ios::trunc);
      output_file_handle << string_to_write;
      output_file_handle.close();
      //cout<< string_to_write;
      channel_number=1;

  }




  int module5(vector<Track> input_score){

      make_your_dream_come_true(do_midi_stuff(input_score));
      channel_number=1;
      WinExec("C:/buildtemp/takeaway/fluidsynthcaller.exe",SW_HIDE);
      dy=1.5;
      return 0;
  }


