#include <avr/pgmspace.h>   
                                                         
//Font                             
const unsigned char font8_8[93][8] PROGMEM =                                 
{                                                            
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // space          
    { 0x00, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00 },   // !           
    { 0x3B, 0xB1, 0xB8, 0xB4, 0xAE, 0xDF, 0xAF, 0x70 },   // "   党徽1          
    { 0xC4, 0x4E, 0x47, 0x4B, 0x51, 0x20, 0x50, 0x8F },  // #   党徽2        
    { 0x00, 0x0C, 0x12, 0x22, 0x44, 0x22, 0x12, 0x0C },   // $   空心        
    { 0x18, 0x24, 0x66, 0x81, 0x81, 0x66, 0x24, 0x18 },   // %   医护十字1          
    { 0x00, 0x18, 0x18, 0x7E, 0x7E, 0x18, 0x18, 0x00 },   // &   医护十字2        
    { 0x00, 0x00, 0x84, 0x82, 0xFF, 0x80, 0x80, 0x00 },   // '           
    { 0x00, 0x80, 0xC6, 0xA1, 0x91, 0x8E, 0x80, 0x00 },   // (   数字2        
    { 0x00, 0x00, 0x42, 0x91, 0x99, 0x66, 0x00, 0x00 },   // )   数字3       
    { 0x00, 0x00, 0x84, 0x82, 0xFF, 0x80, 0x80, 0x00 },   // *   数字1        
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },   // +   箭头1        
    { 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00 },   // ,   箭头2    
    { 0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00 },   // -   箭头3        
    { 0x00, 0x01, 0x03, 0x07, 0x0F, 0x07, 0x03, 0x01 },   // .   箭头4        
    { 0x00, 0x02, 0x06, 0x0F, 0x1F, 0x0F, 0x06, 0x02 },   // /   箭头5        
    { 0x00, 0x04, 0x0C, 0x1F, 0x3F, 0x1F, 0x0C, 0x04 },   // 0   箭头6        
    { 0x00, 0x08, 0x18, 0x3F, 0x7F, 0x3F, 0x18, 0x08 },   // 1   箭头7        
    { 0x00, 0x20, 0x60, 0xFE, 0xFE, 0xFE, 0x60, 0x20 },   // 2   箭头8        
    { 0x00, 0x40, 0xC0, 0xFC, 0xFC, 0xFC, 0xC0, 0x40 },   // 3   箭头9        
    { 0x00, 0x80, 0x80, 0xF8, 0xF8, 0xF8, 0x80, 0x80 },   // 4   箭头10        
    { 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0x00, 0x00 },   // 5   箭头11        
    { 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00 },   // 6   箭头12        
    { 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00 },   // 7   箭头13       
    { 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00 },   // 8   箭头14        
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // 9   箭头15           
    { 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // :   运货1        
    { 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00 },   // ;   运货2        
    { 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00 },   // <      3     
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00 },   // =      4     
    { 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF },   // >      5     
    { 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0xFF },   // ?      6     
    { 0xFF, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF },   // @      7     
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF },   // A      8     
    { 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF },   // B      9     
    { 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x7E, 0xFF },   // C      10     
    { 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x7E, 0xFF },   // D      11   
    { 0x18, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x7E, 0xFF },   // E      12 
    { 0x00, 0x00, 0x18, 0x00, 0x00, 0x3C, 0x7E, 0xFF },   // F      13     
    { 0x00, 0x00, 0x00, 0x00, 0x18, 0x3C, 0x7E, 0xFF },   // G   运货14    
    { 0x00, 0x10, 0x18, 0x14, 0x12, 0xFF, 0x10, 0x10 },   // H   数字4        
    { 0x00, 0x00, 0x8F, 0x89, 0x89, 0x89, 0x71, 0x00 },   // I   数字5        
    { 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 },   // J   X        
    { 0x0E, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1C },   // K          
    { 0x1C, 0x00, 0x00, 0x19, 0x99, 0x81, 0x80, 0x00 },   // L：矩阵结束           
    
    { 0x18, 0x30, 0x30, 0x03, 0x03, 0x86, 0xE0, 0x60 },   // M：三角变换开始           
    { 0x80, 0xE0, 0x86, 0x07, 0x01, 0x30, 0x30, 0x60 },   //N           
    { 0x06, 0x87, 0xE1, 0x60, 0x00, 0x18, 0x18, 0x30 },   // O           
    { 0x18, 0x1C, 0x04, 0x80, 0xE0, 0x66, 0x06, 0x0C },   // P:三角变换结束         
    { 0xC3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70 },   // Q           
    { 0x87, 0x80, 0x80, 0x18, 0x18, 0x00, 0x00, 0x38 },   // R           
    { 0x0E, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1C },   // S          
    { 0x1C, 0x00, 0x00, 0x19, 0x99, 0x81, 0x80, 0x00 },   // T：矩阵结束    
   
    { 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 },   // U: 双花开始           
    { 0x40, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x05, 0x02 },   // V           
    { 0x40, 0xE0, 0x40, 0x00, 0x00, 0x02, 0x07, 0x02 },   // W           
    { 0x00, 0xA0, 0x40, 0xA0, 0x05, 0x02, 0x05, 0x00 },   // X           
    { 0x00, 0x00, 0x40, 0xE2, 0x47, 0x02, 0x00, 0x00 },   // Y           
    { 0x00, 0x00, 0x05, 0xA2, 0x45, 0xA0, 0x00, 0x00 },   // Z           
    { 0x00, 0x02, 0x07, 0x02, 0x40, 0xE0, 0x40, 0x00 },   // [           
    { 0x05, 0x02, 0x05, 0x00, 0x00, 0xA0, 0x40, 0xA0 },   // 55          
    { 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0xE0 },   // ]           
    { 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0 },   // ^  双花结束         
    
    { 0x00, 0x10, 0x38, 0x7C, 0xEE, 0xC6, 0x82, 0x00 },   // _  最终1 0x00, 0x10, 0x38, 0x7C, 0xEE, 0xC6, 0x82, 0x00        
    { 0x00, 0x82, 0xC6, 0xEE, 0x7C, 0x38, 0x10, 0x00 },   // '  最终结束  
    { 0x00, 0x7F, 0x02, 0x04, 0x08, 0x10, 0x20, 0x7F },   // a  'N'          
    { 0x00, 0x20, 0x41, 0x81, 0x7F, 0x01, 0x01, 0x00 },   // b  'J'         
    { 0x00, 0x7F, 0x80, 0x80, 0x40, 0x20, 0xFF, 0x00 },   // c  'U'        
    { 0x3C, 0x66, 0x66, 0x0C, 0x18, 0x18, 0x00, 0x18 },   // d  问号        
    { 0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x0C },   // e  对号         
    { 0x10, 0x10, 0x10, 0x1F, 0xF8, 0x08, 0x08, 0x08 },   // f  十字1         
    { 0x02, 0x84, 0x48, 0x38, 0x1C, 0x12, 0x21, 0x40 },   // g  十字2         
    { 0x7E, 0x89, 0xA5, 0x83, 0xBD, 0xBD, 0x81, 0x7E },   // h  刀     
    { 0x3c, 0x42, 0x95, 0xa1, 0xa1, 0x95, 0x42, 0x3c },   // i  笑脸  
    { 0x10, 0x70, 0xF0, 0xF0, 0xF0, 0xF0, 0x70, 0x10 },   // j  口罩               
    { 0x00, 0x04, 0x06, 0x07, 0x07, 0x06, 0x04, 0x00 },   // k 搜寻1          
    { 0x00, 0x04, 0x06, 0x0F, 0x0F, 0x06, 0x04, 0x00 },   // l           
    { 0x00, 0x14, 0x26, 0x2F, 0x2F, 0x26, 0x14, 0x00 },   // m 
    { 0x20, 0x54, 0xA6, 0xAF, 0xAF, 0xA6, 0x54, 0x20 },   // n 搜寻4        
       
    //{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18 },   // k 搜寻1          
    //{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x18 },   // l           
    //{ 0x00, 0x00, 0x00, 0x3C, 0x42, 0x18, 0x24, 0x18 },   // m           
    //{ 0x3C, 0x42, 0x81, 0x3C, 0x42, 0x18, 0x24, 0x18 },   // n 搜寻4            
    { 0x00, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00 },   // o           
    { 0x41, 0x6B, 0x7F, 0x7F, 0x7F, 0x3E, 0x1C, 0x08 },   // p 蓝盾         
    { 0x00, 0x00, 0x00, 0xDF, 0xDF, 0x00, 0x00, 0x00 },   // q 感叹号          
    { 0x00, 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, 0x00 },   // r           
    { 0x00, 0x18, 0x24, 0x20, 0x18, 0x04, 0x24, 0x18 },   // s前进箭头           
    { 0x00, 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, 0x00 },   // t           
    { 0x00, 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00 },   // u           
    { 0x00, 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00 },   // v           
    { 0x00, 0x08, 0x1C, 0x00, 0x00, 0x22, 0x77, 0x00 },   // w:三者出击           
    { 0x08, 0x0C, 0xFE, 0xFF, 0xFE, 0xCC, 0xC8, 0xC0 },   // x右转箭头          
    { 0x10, 0x30, 0x7F, 0xFF, 0x7F, 0x33, 0x13, 0x03 },   // y左转箭头 
     { 0x10, 0x30, 0x7F, 0xFF, 0x7F, 0x30, 0x10, 0x00 } ,   //z前进箭头，改成z就行了             
    { 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x06, 0x00 },   // horiz lines 

}; 

//pic
const unsigned char pic[6][8][8][3] PROGMEM = {
                                 {{{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}},
                                  {{255,0,0},     {255,0,0},      {255,0,0},     {255,0,0},  {255,0,0},     {255,0,0},      {255,0,0},     {255,0,0}}
                                 },
                                 
                                 {{{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                  {{0,255,0},      {0,255,0},       {0,255,0},        {0,255,0},    {0,255,0},      {0,255,0},       {0,255,0},        {0,255,0}},
                                 },
                                 
                                 {{{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                  {{0,0,255},     {0,0,255},      {0,0,255},     {0,0,255},   {0,0,255},     {0,0,255},      {0,0,255},     {0,0,255}},
                                 },
                                 
                                 {{{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}},
                                  {{255,255,254},     {255,255,255},      {255,255,255},     {255,255,255},    {255,255,255},      {255,255,255},       {255,255,255},        {255,255,255}}
                                 },
                                 
                                 {{{254,254,254},     {254,254,254},      {254,254,254},     {254,254,254},    {254,254,254},      {254,254,254},       {254,254,254},        {254,254,254}},
                                  {{255,255,254},     {0,0,0},            {0,0,0},           {254,254,254},    {254,254,254},      {0,0,0},             {0,0,0},              {254,254,254}},
                                  {{255,255,254},     {0,0,0},            {254,254,254},     {0,0,0},          {0,0,0},            {254,254,254},       {0,0,0},              {254,254,254}},
                                  {{255,255,254},     {254,254,254},      {0,0,0},           {0,0,0},          {0,0,0},            {0,0,0},             {254,254,254},        {254,254,254}},
                                  {{255,255,254},     {0,0,0},            {254,254,254},     {254,254,254},    {254,254,254},      {254,254,254},       {0,0,0},              {254,254,254}},
                                  {{255,255,254},     {0,0,0},            {254,254,254},     {0,0,0},          {0,0,0},            {254,254,254},       {0,0,0},              {254,254,254}},
                                  {{255,255,254},     {0,0,0},            {254,254,254},     {254,254,254},    {254,254,254},      {254,254,254},       {0,0,0},              {254,254,254}},
                                  {{255,255,254},     {254,254,254},      {254,254,254},     {254,254,254},    {254,254,254},      {254,254,254},       {254,254,254},        {254,254,254}}
                                 },
                                 
                                 {{{0,0,0},           {0,0,0},            {0,0,0},           {0,0,0},          {0,0,0},            {0,0,0},             {0,0,0},              {0,0,0}},
                                  {{0,0,0},           {254,254,254},      {254,254,254},     {0,0,0},          {0,0,0},            {254,254,254},       {254,254,254},        {0,0,0}},
                                  {{0,0,0},           {254,254,254},      {0,0,0},           {0,0,0},          {0,0,0},            {0,0,0},             {254,254,254},        {0,0,0}},
                                  {{0,0,0},           {0,0,0},            {0,0,0},           {254,254,254},    {254,254,254},      {0,0,0},             {0,0,0},              {0,0,0}},
                                  {{0,0,0},           {0,0,0},            {0,0,0},           {254,254,254},    {254,254,254},      {0,0,0},             {0,0,0},              {0,0,0}},
                                  {{0,0,0},           {254,254,254},      {0,0,0},           {0,0,0},          {0,0,0},            {0,0,0},             {254,254,254},        {0,0,0}},
                                  {{0,0,0},           {0,0,0},            {254,254,254},     {254,254,254},    {254,254,254},      {254,254,254},       {0,0,0},              {0,0,0}},
                                  {{0,0,0},           {0,0,0},            {0,0,0},           {0,0,0},          {0,0,0},            {0,0,0},             {0,0,0},              {0,0,0}}
                                 }
};
