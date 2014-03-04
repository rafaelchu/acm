{ Problem 178: Shuffling Patience }

PROGRAM SomeProg;

CONST probname = 'SP92_';
      prob_id = 'H';
VAR debugcounter: integer;

PROCEDURE get_data;              forward;
FUNCTION  ReadData: Boolean;     forward;
PROCEDURE SolveProblem;          forward;

type
  card_type = record
      face, suit: char;
      value: 1..13;
    end;

var
  deck: array[1..52] of card_type;
  grid: array[1..16] of record
                   topcard: card_type;
                   count: integer end;
  thischar: char;
  bigN, dealNo: integer;
  count: integer;

PROCEDURE Error(s:string);
begin
  writeln; writeln(s); HALT;
end;

PROCEDURE MainProg;
begin  {Main}


get_data; dealNo := 0;
while ReadData do
  SolveProblem;

end; {of main procedure}

procedure get_data;
begin
read(thischar);
if eoln then readln;
while (thischar = ' ') do read(thischar);
{**writeln('read_data "',thischar,'"');{**}
end;

PROCEDURE get_card(var card: card_type);
begin
with card do begin
  face := thischar;
{**write('card = ',face);{**}
  case face of
    'A':      value := 1;
    '2'..'9': value := ord(face) - ord('0');
    'T':      value := 10;
    'J':      value := 11;
    'Q':      value := 12;
    'K':      value := 13;
    otherwise begin writeln('Funny character ',face);HALT end;{**}
    end;  {case}
  get_data; suit := thischar;
{**writeln(suit);{**}
  get_data;
  end;
end;

function ReadData: Boolean;
var loop: integer;

begin
ReadData := true;
if thischar = '#'
  then ReadData := false
  else for loop := 1 to 52 do get_card(deck[loop]);
end;

PROCEDURE SolveProblem;
var cardptr: integer;
    i, j, k: integer;
    vi, vj, vk : integer;
    court: set of 11..13;
    played: Boolean;

PROCEDURE Play(n: integer);
begin
if cardptr in [1..52]
  then begin count := count + 1;
{**with deck[cardptr] do write(cardptr:2, ': playing ',face,suit, ' to ',n:2, ' ');readln;{**}
    with grid[n] do begin
      count := count + 1; topcard := deck[cardptr] end;
    cardptr := cardptr + 1; played := true;
    end;
end;

begin  {Solve Problem}
cardptr := 1; bigN := 0; dealNo := dealNo + 1; write(DealNo:3, ':');
for i := 1 to 16 do grid[i].count := 0;
count := 0;
while cardptr < 53 do begin
  i := 0; played := false;
  while (i < bigN-1) and not played do begin
    i := i + 1; vi := grid[i].topcard.value; court := [11, 12, 13];
    if vi in court
      then begin
        court := court - [vi]; j := i;
          while (j < bigN) and not played do begin
            j := j + 1; vj := grid[j].topcard.value;
            if vj in court
              then begin
                court := court - [vj]; k := j;
                  while (k < bigN) and not played do begin
                    k := k + 1; vk := grid[k].topcard.value;
                    if vk in court
                      then begin play(i); play(j); play(k) end;
                    end;  {k < bigN}
                end;  {vj in court - go look for the last}
            end;  {while j < bigN}
        end  {vi in court - start looking}
      else begin j := i;
        while (j < bigN) and not played do begin
          j := j + 1; vj := grid[j].topcard.value;
          if vi + vj = 11
            then begin play(i); play(j) end;
          end;  {j < bigN}
        end;  {i not in court - went looking for 11}
    end;  {while i < bigN-1}
  if not played
    then begin bigN := bigN + 1;
      if bigN < 17
        then play(bigN)
        else begin writeln(' Overflowed on card no', cardptr:3); cardptr := 100 end;
      end;  {not played}
  end;  {while cardptr < 52}
if cardptr <> 100 then
   begin
   for i := 1 to bigN do write(grid[i].count:3); writeln;
   {**}if count <> 52 then begin write('foulup ', count);readln;end;{**}
   end;
end;  {Solve Problem}

begin mainprog end.
