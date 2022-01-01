struct LuaExample
{
	char* name;
	char* lua;
};
const LuaExample luaExamples [] =
{
	{
	"Lua basics / cheatsheet",
	
	"-- Lua introduction / cheatsheet\n"
	"\n"
	"-- This is single-line comment\n"
	"--[[\n"
	"   This is multi-line\n"
	"   comment.\n"
	"--]]\n"
	"\n"
	"-- Undefined variables return nil (not generating error)\n"
	"local str = 'text'    -- Variable declaration/definition; global by default\n"
	"str = nil       -- Undefines \"str\" variable; Lua uses garbage collector\n"
	"\n"
	"-- Note: print output goes to log\n"
	"print(\"\\n\\n##### Starting script #####\\n\\n\")\n"
	"\n"
	"-- Conditionals\n"
	"local num = 5\n"
	"if num > 6 then\n"
	"    print('num is larger than 6\\n')   -- print output goes to tSIP log window\n"
	"elseif num == 23 then               -- equality operator: ==\n"
	"    print('num equals 23\\n')       -- also -> tSIP log window\n"
	"else\n"
	"\t-- local variable\n"
	"    local messageText = string.format(\"Num value = %d\\n\", num);\n"
	"    print(messageText)\n"
	"end\n"
	"\n"
	"if 0 then\n"
	"    print(\"Only nil and false values are interpreted as false condition\\n\")\n"
	"end\n"
	"\n"
	"-- Multi-line comments can be used as C's \"#if 0\"\n"
	"-- Remove one '-' from line below to disable this block\n"
	"---[[\n"
	"\tprint(\"Block of code - enabled\\n\")\n"
	"--]]\n"
	"\n"
	"-- Loops\n"
	"\n"
	"while num < 10 do\n"
	"\tprint(\"Incrementing num\\n\")\n"
	"\tnum = num + 1  -- No ++/-- or += type (shorthand) operators.\n"
	"end\n"
	"\n"
	"local sum = 0\n"
	"for i = 1, num do  -- Range includes both ends.\n"
	"\tsum = sum + i\n"
	"end\n"
	"print(string.format(\"Sum of numbers from 1 to %d: %d\\n\", num, sum))\n"
	"\n"
	"for j = 3, 1, -1 do\n"
	"\t-- \"..\" = concatenation operator\n"
	"\tprint(\"Counting down: \" .. j .. \"\\n\")\n"
	"end\n"
	"\n"
	"repeat\n"
	"\tnum = num - 1\n"
	"until num == 0\n"
	"\n"
	"-- Tables are indexed by default by integers (starting from 1)\n"
	"local myTable = {'first value', 'second value', 3, 4.76}\n"
	"print 'myTable values: '\n"
	"for i = 1, #myTable do  -- #myTable = table size\n"
	"\tif i ~= 1 then\n"
	"\t\tprint ', '\n"
	"\tend\n"
	"\tprint (myTable[i])\n"
	"end\n"
	"print '\\n'\n"
	"\n"
	"\n"
	"print(\"\\n\\n##### End of script #####\\n\\n\")"
	}
	,
	{
	"Beep",

	"-- ShowMessage(\"Press \\\"Break\\\" to stop\")\n"
	"local pattern =\n"
	"{\n"
	"-- frequency, time\n"
	"{392 \t,350},\n"
	"{392 \t,350},\n"
	"{392 \t,350},\n"
	"{311 \t,250},\n"
	"{466 \t,250},\n"
	"{392 \t,350},\n"
	"{311 \t,250},\n"
	"{466 \t,250},\n"
	"{392 \t,700},\n"
	"{587 ,350},\n"
	"{587 ,350},\n"
	"{587 ,350},\n"
	"{622 ,250},\n"
	"{466 \t,250},\n"
	"{369 ,350},\n"
	"{311 \t,250},\n"
	"{466 \t,250},\n"
	"{392 \t,700},\n"
	"{784 \t,350},\n"
	"{392 \t,250},\n"
	"{392 \t,250},\n"
	"{784 \t,350},\n"
	"{739 ,250},\n"
	"{698 ,250},\n"
	"{659 ,250},\n"
	"{622 ,250},\n"
	"{659 ,500},\n"
	"{0, 300},\n"
	"{415 \t,250},\n"
	"{0,100},\n"
	"{554 ,350},\n"
	"{523 ,250},\n"
	"{493 ,250},\n"
	"{466 ,250},\n"
	"{440 \t,250},\n"
	"{466 ,500},\n"
	"{0,300},\n"
	"{311 ,250},\n"
	"{0,100},\n"
	"{369 ,350},\n"
	"{311 ,250},\n"
	"{392 \t,250},\n"
	"{466 ,350},\n"
	"{392 \t,250},\n"
	"{466 ,250},\n"
	"{587 ,700},\n"
	"{784 \t,350},\n"
	"{392 \t,250},\n"
	"{392 \t,250},\n"
	"{784 \t,350},\n"
	"{739 ,250},\n"
	"{698 ,250},\n"
	"{659 ,250},\n"
	"{622 ,250},\n"
	"{659 ,500},\n"
	"{0,300},\n"
	"{415 \t,250},\n"
	"{0,100},\n"
	"{554 ,350},\n"
	"{523 ,250},\n"
	"{493 ,250},\n"
	"{466 ,250},\n"
	"{440 \t,250},\n"
	"{466 ,500},\n"
	"{0,300},\n"
	"{311 ,250},\n"
	"{0,200},\n"
	"{392 \t,250},\n"
	"{311 ,250},\n"
	"{466 ,250},\n"
	"{392 ,300},\n"
	"{0,500},\n"
	"{311 ,250},\n"
	"\n"
	"}\n"
	"\n"
	"local winapi = require(\"tsip_winapi\")\n"
	"\n"
	"for i = 1, #pattern do\n"
	"\twinapi.Beep(pattern[i][1], pattern[i][2])\n"
	"\tlocal ret = CheckBreak()\n"
	"\tSleep(100)\t-- process Win messages also\n"
	"\t-- break on user request\\n\"\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	""
	},

	{
	"Calling: loop",

	"-- calling specified number in the loop\n"
	"print(string.format(\"Running %s on %s\\n\", _VERSION, os.date()))\n"
	"-- seed random number generator\n"
	"math.randomseed(os.time())\n"
	"-- clear digits already in Dial edit to be sure\n"
	"for i = 1, 10 do\n"
	"\tCall(\"2007\")\n"
	"\tSleep(2000)\n"
	"\tHangup()\n"
	"\t-- random pause between the calls: 2000...5000 ms\n"
	"\tSleep(math.random(2000, 5000))\n"
	"\tlocal ret = CheckBreak()\n"
	"\t-- break on user request\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	"print(\"Done\\n\");"

	},

	{
	"Calling numbers from list",

	"-- calling numbers from the list\n"
	"local numbers = {\n"
	"\t'1000',\n"
	"\t'1001',\n"
	"\t'1002'\n"
	"}\n"
	"for i = 1, #numbers do\n"
	"\tCall(numbers[i])\n"
	"\tSleep(4000)\n"
	"\tHangup()\n"
	"\tSleep(1000)\n"
	"\tlocal ret = CheckBreak()\n"
	"\t-- break on user request\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tbreak\n"
	"\tend\n"
	"end"
	},

	{
	"Call + DTMFs",
	
	"-- calling and sending DTMFs\n"
	"print(string.format(\"Running %s on %s\\n\", _VERSION, os.date()))\n"
	"Call(\"2000\")\n"
	"Sleep(5000)\n"
	"-- hoping that 2nd party would answer the call in meantime\n"
	"SendDtmf(\"012345678*#\")\n"
	"-- pause to let digits get out of the queues safely\n"
	"Sleep(3000)\n"
	"Hangup()\n"
	"print(\"Done\\n\");"
	},

	{
	"Call to specified number (conference room) and enter code",

	"-- user config\n"
	"local number = \"123456789\"\n"
	"local dtmf = \"1234\"\n"
	"-- end of user config\n"
	" \n"
	"Call(number)\n"
	"for i=1, 20, 1\n"
	"do\n"
	"\tif (i == 20) then\n"
	"\t\tprint(\"Timed out waiting for confirmed state\\n\")\n"
	"\t\tbreak;\n"
	"\tend\n"
	" \n"
	"\tSleep(300)\n"
	"\tlocal call_state = GetCallState()\n"
	"\tif call_state == 6 then\n"
	"\t\t-- CALL_STATE_ESTABLISHED\n"
	"\t\tSleep(2000)\n"
	"\t\tSendDtmf(dtmf)\n"
	"\t\tbreak\n"
	"\telseif call_state == 0 then\n"
	"\t\t-- CALL_STATE_CLOSED\n"
	"\t\tprint(\"End of call\\n\")\n"
	"\t\tbreak;\n"
	"\tend\n"
	"end\n"
	"print(\"End of script\\n\")"
	}
	,
	{
	"Count number of times script was executed",
	
	"-- This script counts number of times it was executed\n"
	"local count, var_isset = GetVariable(\"runcount\")\n"
	"if (var_isset == 0) then\n"
	"\tcount = 0\n"
	"else\n"
	"\tcount = tonumber(count)\n"
	"end\n"
	"\n"
	"count = count + 1\n"
	"SetVariable(\"runcount\", count)\n"
	"print(string.format(\"Script executed %d time(s)\\n\", count))"
	}
	,
	{
	"PlaySound",

	"-- Playing sound asynchronously\n"
	"-- note: more powerful (sound device selection) option is using sox tool + ShellExecute\n"
	"-- (http://tomeko.net/software/SIPclient/howto/sox.php, http://tomeko.net/software/SIPclient/howto/local_dtmfs.php)\n"
	"\n"
	"local winapi = require(\"tsip_winapi\")\n"
	"\n"
	"-- let's use path relative to exe location\n"
	"local filename = GetExeName()\n"
	"local index = string.find(filename:reverse(), \"\\\\\")\n"
	"local dir = string.sub(filename, 1, -index)\n"
	"local audio_file = dir .. \"pluck.wav\"\n"
	"\n"
	"-- PlaySound is identical to WinAPI function with same name\n"
	"local SND_FILENAME = tonumber(0x00020000)\n"
	"local SND_ASYNC = tonumber(0x0001)\n"
	"winapi.PlaySound(audio_file, 0, SND_FILENAME | SND_ASYNC)"
	}
	,
	{
	"Determining event type/id that triggered script",

	"-- Determining event type and id (e.g. button id) that triggered script\n"
	"-- see: enum ScriptSource\n"
	"local execSourceType = GetExecSourceType()\n"
	"print(\"Source: \")\n"
	"if execSourceType == 0 then\n"
	"\tprint(\"button\")\n"
	"elseif execSourceType == 1 then\n"
	"\tprint(\"making call\")\n"
	"elseif execSourceType == 2 then\n"
	"\tprint(\"call state change\")\n"
	"elseif execSourceType == 3 then\n"
	"\tprint(\"streaming state\")\n"
	"elseif execSourceType == 4 then\n"
	"\tprint(\"registration state\")\n"
	"elseif execSourceType == 5 then\n"
	"\tprint(\"startup\")\n"
	"elseif execSourceType == 6 then\n"
	"\tprint(\"timer\")\n"
	"elseif execSourceType == 7 then\n"
	"\tprint(\"dialog info (BLF)\")\n"
	"elseif execSourceType == 8 then\n"
	"\tprint(\"dialing\")\n"
	"elseif execSourceType == 9 then\n"
	"\tprint(\"script window\")\n"
	"elseif execSourceType == 10 then\n"
	"\tprint(\"audio error (e.g. end of wav file)\")\n"
	"elseif execSourceType == 11 then\n"
	"\tprint(\"plugin\")\n"
	"elseif execSourceType == 12 then\n"
	"\tprint(\"custom request status/reply\")\n"
	"elseif execSourceType == 13 then\n"
	"\tprint(\"on contact note open\")\n"
	"elseif execSourceType == 14 then\n"
	"\tprint(\"on recorder state\")\n"
	"elseif execSourceType == 15 then\n"
	"\tprint(\"command line\")\n"
	"elseif execSourceType == 16 then\n"
	"\tprint(\"button mouse up/down\")\n"
	"elseif execSourceType == 17 then\n"
	"\tprint(\"encryption state\")\n"
	"else\n"
	"\tprint(string.format(\"type = %d, missing description\", execSourceType))\n"
	"end\n"
	"local execSourceId = GetExecSourceId()\n"
	"print(string.format(\", ID = %d\\n\", execSourceId))"
	}
	,
	{
	"Determining current call state",

	"-- Determining call state\n"
	"-- see: enum Callback::ua_state_e\n"
	"local callState = GetCallState()\n"
	"print(\"Call state: \")\n"
	"if callState == 0 then\n"
	"\tprint(\"CLOSED\")\n"
	"elseif callState == 1 then\n"
	"\tprint(\"INCOMING\")\n"
	"elseif callState == 2 then\n"
	"\tprint(\"OUTGOING\")\n"
	"elseif callState == 3 then\n"
	"\tprint(\"TRYING\")\n"
	"elseif callState == 4 then\n"
	"\tprint(\"RINGING\")\n"
	"elseif callState == 5 then\n"
	"\tprint(\"PROGRESS\")\n"
	"elseif callState == 6 then\n"
	"\tprint(\"ESTABLISHED\")\n"
	"elseif callState == 7 then\n"
	"\tprint(\"TRANSFER\")\n"
	"elseif callState == 8 then\n"
	"\tprint(\"TRANSFER_OOD\")\n"
	"else\n"
	"\tprint(string.format(\"type = %d, missing description\", callState))\n"
	"end\n"
	"local execSourceId = GetExecSourceId()\n"
	"print(string.format(\", numeric value = %d\\n\", callState))"
	}
	,
	{
	"Send custom SIP request to single target",
	
	"function string.starts(String, Start)\n"
	"   return string.sub(String,1,string.len(Start))==Start\n"
	"end\n"
	"\n"
	"function trim(s)\n"
	"  return (s:gsub(\"^%s*(.-)%s*$\", \"%1\"))\n"
	"end\n"
	"\n"
	"local target = \"sip:208@192.168.1.211\"\n"
	"local requestUid = SendCustomRequest(target, \"OPTIONS\", \"Accept: application/sdp\\r\\nContent-Length: 0\\r\\n\\r\\n\")\n"
	"if requestUid <= 0 then\n"
	"\tprint(string.format(\"Error sending custom request to %s\\n\", target))\n"
	"\treturn\n"
	"end\n"
	"\n"
	"\n"
	"for i=1,20 do\n"
	"\tlocal ret = CheckBreak()\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint(\"User break\\n\")\n"
	"\t\tbreak\n"
	"\tend\n"
	"\tSleep(400)\n"
	"\n"
	"\n"
	"\tlocal haveReply, err, sipStatusCode = GetCustomRequestReply(requestUid)\n"
	"\tif haveReply ~= 0 then\n"
	"\t\tlocal uri = GetCustomRequest(requestUid)\n"
	"\t\tif err == 0 then\n"
	"\t\t\tlocal replyText = GetCustomRequestReplyText(requestUid)\n"
	"\t\t\t-- print(string.format(\"Reply text:\\n%s\\n\", replyText))\n"
	"\t\t\tprint(string.format(\"**** URI %s => SIP status %d\\n\", uri, sipStatusCode))\n"
	"\t\t\tlocal needle = \"USER-AGENT:\"\n"
	"\t\t\tlocal needle2 = \"SERVER:\"\n"
	"\t\t\tfor line in replyText:gmatch\"[^\\n]+\" do\t-- extract each line\n"
	"\t\t\t\tlocal uline = string.upper(line)\n"
	"\t\t\t\tif string.starts(uline, needle) then\n"
	"\t\t\t\t\tlocal lineVal = trim(line:sub(string.len(needle)+1))\n"
	"\t\t\t\t\tprint(string.format(\"    **** URI %s => User-Agent value: %s\\n\", uri, lineVal))\n"
	"\t\t\t\t\tbreak\n"
	"\t\t\t\telseif string.starts(uline, needle2) then\n"
	"\t\t\t\t\tlineVal = trim(line:sub(string.len(needle2)+1))\n"
	"\t\t\t\t\tprint(string.format(\"    **** URI %s => Server value: %s\\n\", uri, lineVal))\n"
	"\t\t\t\t\tbreak\n"
	"\t\t\t\tend\n"
	"\t\t\tend\n"
	"\t\telse\n"
	"\t\t\t-- print(string.format(\"**** URI %s => err = %d\\n\", uri, err))\n"
	"\t\tend\n"
	"\n"
	"\t\tDeleteCustomRequest(requestUid)\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	"\n"
	"\n"
	"ClearCustomRequests()\n"
	}
	,
	{
	"Scan local network (192.168.0.*:5060) with OPTIONS",

	"function string.starts(String, Start)\n"
	"   return string.sub(String,1,string.len(Start))==Start\n"
	"end\n"
	"\n"
	"function trim(s)\n"
	"  return (s:gsub(\"^%s*(.-)%s*$\", \"%1\"))\n"
	"end\n"
	"\n"
	"\n"
	"local requestUidTable = {}\n"
	"\n"
	"-- note: command/callback queues are limited to 1024 elements each (v0.1.68.5)\n"
	"local targetStart = \"sip:192.168.0.\"\n"
	"local port = \":5060\"\n"
	"for i=1,254 do\n"
	"\tlocal target = targetStart .. i .. port\n"
	"\tlocal requestUid = SendCustomRequest(target, \"OPTIONS\", \"Accept: application/sdp\\r\\nContent-Length: 0\\r\\n\\r\\n\")\n"
	"\tif requestUid > 0 then\n"
	"\t\ttable.insert(requestUidTable, requestUid)\n"
	"\telse\n"
	"\t\tprint(string.format(\"Error sending custom request to %s\\n\", target))\n"
	"\tend\n"
	"\tSleep(10)\n"
	"\tret = CheckBreak()\n"
	"\tif ret ~= 0 then\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	"\n"
	"\n"
	"for i=1,100 do\n"
	"\tret = CheckBreak()\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint(\"User break\\n\")\n"
	"\t\tbreak\n"
	"\tend\n"
	"\tSleep(400)\n"
	"\n"
	"\tlocal n = #requestUidTable\n"
	"\tif n == 0 then\n"
	"\t\tbreak\n"
	"\tend\n"
	"\n"
	"\tfor index, requestUid in ipairs(requestUidTable) do\n"
	"\t\tlocal haveReply, err, sipStatusCode = GetCustomRequestReply(requestUid)\n"
	"\t\tif haveReply ~= 0 then\n"
	"\t\t\tlocal uri = GetCustomRequest(requestUid)\n"
	"\t\t\tif err == 0 then\n"
	"\t\t\t\tlocal replyText = GetCustomRequestReplyText(requestUid)\n"
	"\t\t\t\t-- print(string.format(\"Reply text:\\n%s\\n\", replyText))\n"
	"\t\t\t\tprint(string.format(\"**** URI %s => SIP status %d\\n\", uri, sipStatusCode))\n"
	"\t\t\t\tlocal needle = \"USER-AGENT:\"\n"
	"\t\t\t\tlocal needle2 = \"SERVER:\"\n"
	"\t\t\t\tfor line in replyText:gmatch\"[^\\n]+\" do\t-- extract each line\n"
	"\t\t\t\t\tlocal uline = string.upper(line)\n"
	"\t\t\t\t\tif string.starts(uline, needle) then\n"
	"\t\t\t\t\t\tlineVal = trim(line:sub(string.len(needle)+1))\n"
	"\t\t\t\t\t\tprint(string.format(\"    **** URI %s => User-Agent value: %s\\n\", uri, lineVal))\n"
	"\t\t\t\t\t\tbreak\n"
	"\t\t\t\t\telseif string.starts(uline, needle2) then\n"
	"\t\t\t\t\t\tlineVal = trim(line:sub(string.len(needle2)+1))\n"
	"\t\t\t\t\t\tprint(string.format(\"    **** URI %s => Server value: %s\\n\", uri, lineVal))\n"
	"\t\t\t\t\t\tbreak\n"
	"\t\t\t\t\tend\n"
	"\t\t\t\tend\n"
	"\t\t\telse\n"
	"\t\t\t\t-- print(string.format(\"**** URI %s => err = %d\\n\", uri, err))\n"
	"\t\t\tend\n"
	"\n"
	"\t\t\tDeleteCustomRequest(requestUid)\n"
	"\t\t\trequestUidTable[index] = nil\n"
	"\n"
	"\t\tend\n"
	"\tend\n"
	"\n"
	"\t-- traverse array again, compacting it\n"
	"\tlocal j=0\n"
	"\tfor i2 = 1, n do\n"
	"\t\t\tif requestUidTable[i2]~=nil then\n"
	"\t\t\t\t\tj=j+1\n"
	"\t\t\t\t\trequestUidTable[j]=requestUidTable[i2]\n"
	"\t\t\tend\n"
	"\tend\n"
	"\tfor i2 = j+1, n do\n"
	"\t\t\trequestUidTable[i2]=nil\n"
	"\tend\n"
	"end\n"
	"\n"
	"\n"
	"ClearCustomRequests()\n"
	""
	}
	,
	{
	"Lenny"
	,
	"local audioErrCnt = GetAudioErrorCount()\n"
	"local avgAudioLevel = 0\n"
	"\n"
	"function UpdateAvgAudioLevel()\t-- part of the VAD\n"
	"\tlocal signalLevel = GetAudioRxSignalLevel()\n"
	"\tlocal coeff = 0.95\n"
	"\tavgAudioLevel = avgAudioLevel * coeff + signalLevel * (1-coeff)\n"
	"end\n"
	"\n"
	"function WaitForEndOfWavFile()\n"
	"\twhile true do\n"
	"\t\tlocal cb = CheckBreak();\n"
	"\t\tif cb ~= 0 then\n"
	"\t\t\tprint ('User break\\n')\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal callState = GetCallState()\n"
	"\t\tif callState == 0 then\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal errCnt = GetAudioErrorCount()\n"
	"\t\t-- print(string.format(\"WaitForEndOfWavFile: errCnt = %u\\n\", errCnt))\n"
	"\t\tif errCnt ~= audioErrCnt then\n"
	"\t\t\taudioErrCnt = errCnt\n"
	"\t\t\treturn true;\n"
	"\t\tend\n"
	"\t\tUpdateAvgAudioLevel()\n"
	"\t\tSleep(50)\n"
	"\tend\n"
	"end\n"
	"\n"
	"function WaitForVoice()\n"
	"\tlocal levelCnt = 0\n"
	"\tfor i=1, 500, 1 do\n"
	"\t\tlocal cb = CheckBreak();\n"
	"\t\tif cb ~= 0 then\n"
	"\t\t\tprint ('User break\\n')\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal callState = GetCallState()\n"
	"\t\tif callState == 0 then\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal signalLevel = GetAudioRxSignalLevel()\n"
	"\t\t-- print(string.format(\"WaitForVoice: signalLevel = %d, levelCnt = %d\\n\", signalLevel, levelCnt))\n"
	"\t\tif signalLevel > 500 then\n"
	"\t\t\tif signalLevel > 4000 or signalLevel > avgAudioLevel * 5 or avgAudioLevel > signalLevel * 5 then\n"
	"\t\t\t\tlevelCnt = levelCnt + 1\n"
	"\t\t\t\tif levelCnt > 20 then\n"
	"\t\t\t\t\treturn true\n"
	"\t\t\t\tend\n"
	"\t\t\tend\n"
	"\t\tend\n"
	"\t\tUpdateAvgAudioLevel()\n"
	"\t\tSleep(50)\n"
	"\tend\n"
	"\treturn false\n"
	"end\n"
	"\n"
	"function WaitForSilence()\n"
	"\tlocal i\n"
	"\tlocal levelCnt = 0\n"
	"\tfor i=1, 2000, 1 do\n"
	"\t\tlocal cb = CheckBreak();\n"
	"\t\tif cb ~= 0 then\n"
	"\t\t\tprint ('User break\\n')\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal callState = GetCallState()\n"
	"\t\tif callState == 0 then\n"
	"\t\t\treturn false\n"
	"\t\tend\n"
	"\t\tlocal signalLevel = GetAudioRxSignalLevel()\n"
	"\t\t-- print(string.format(\"WaitForSilence: signalLevel = %d, levelCnt = %d\\n\", signalLevel, levelCnt))\n"
	"\t\tif signalLevel < 500 or (signalLevel < 3000 and signalLevel < avgAudioLevel * 1.25 and avgAudioLevel < signalLevel * 1.25) then\n"
	"\t\t\tlevelCnt = levelCnt + 1\n"
	"\t\t\tif levelCnt > 30 then\n"
	"\t\t\t\treturn true\n"
	"\t\t\tend\n"
	"\t\telse\n"
	"\t\t\tlevelCnt = 0\n"
	"\t\tend\n"
	"\t\tUpdateAvgAudioLevel()\n"
	"\t\tSleep(50)\n"
	"\tend\n"
	"\treturn false\n"
	"end\n"
	"\n"
	"local jsonString = [[\n"
	"{\n"
	"   \"Calls\" : {\n"
	"      \"DisconnectCallOnAudioError\" : false\n"
	"   }\n"
	"}\n"
	"]]\n"
	"UpdateSettings(jsonString)\t-- making sure call would not be disconnected at the end of wav file\n"
	"\n"
	"print(\"Lenny: anwering...\\n\")\n"
	"Answer()\n"
	"\n"
	"SwitchAudioSource(\"nullaudio\", \"\")\n"
	"Sleep(1500)\n"
	"\n"
	"local callState = GetCallState()\n"
	"if callState ~= 6 then -- ESTABLISHED\n"
	"\tprint(string.format(\"Lenny: Unexpected: callState = %d\\n\", callState))\n"
	"\tHangup()\n"
	"\treturn\n"
	"end\n"
	"\n"
	"--[[\n"
	"-- single-cycle, disconnecting after last announcement; use \"---\" above to enable, \"--\" to disable code block\n"
	"for i=1, 15 do\n"
	"\tlocal name = string.format(\"Lenny%d.wav\", i)\n"
	"\tSwitchAudioSource(\"aufile\", name)\n"
	"\tWaitForEndOfWavFile()\n"
	"\tWaitForVoice();\n"
	"\tWaitForSilence();\n"
	"\tlocal cb = CheckBreak();\n"
	"\tif cb ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tHangup()\n"
	"\t\treturn\n"
	"\tend\n"
	"end\n"
	"\n"
	"SwitchAudioSource(\"aufile\", \"Lenny16-rickroll.wav\")\n"
	"WaitForEndOfWavFile()\n"
	"\n"
	"Hangup()\n"
	"--]]\n"
	"\n"
	"\n"
	"---[[\n"
	"-- looped 10 times; use \"---\" above to enable, \"--\" to disable code block\n"
	"local name = string.format(\"Lenny1.wav\")\n"
	"SwitchAudioSource(\"aufile\", name)\n"
	"WaitForEndOfWavFile()\n"
	"WaitForVoice();\n"
	"WaitForSilence();\n"
	"\n"
	"for j=1, 10 do\n"
	"\tfor i=2, 16 do\n"
	"\t\tlocal name = string.format(\"Lenny%d.wav\", i)\n"
	"\t\tSwitchAudioSource(\"aufile\", name)\n"
	"\t\tWaitForEndOfWavFile()\n"
	"\t\tWaitForVoice();\n"
	"\t\tWaitForSilence();\n"
	"\t\tlocal cb = CheckBreak();\n"
	"\t\tif cb ~= 0 then\n"
	"\t\t\tbreak\n"
	"\t\tend\n"
	"\tend\n"
	"\tlocal cb = CheckBreak();\n"
	"\tif cb ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tbreak\n"
	"\tend\n"
	"\tcallState = GetCallState()\n"
	"\tif callState ~= 6 then -- ESTABLISHED\n"
	"\t\tprint(\"Lenny: end of call\\n\")\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	"Hangup()\n"
	"--]]"
	}
    ,
    {
	"Send text messages (SIP SIMPLE, instant messanging)"
	,    
    "local target = \"209\"\t-- can use full SIP URI also\n"
    "for i = 1, 10 do\n"
    "\tlocal text = string.format(\"tSIP message #%d\", i)\n"
    "\tSendTextMessage(target, text, 1)\n"
    "\t-- random pause between messages: 200...2000 ms\n"
    "\tSleep(math.random(200, 2000))\n"
    "\tlocal ret = CheckBreak()\n"
	"\t-- break on user request\n"
	"\tif ret ~= 0 then\n"
	"\t\tprint ('User break\\n')\n"
	"\t\tbreak\n"
	"\tend\n"
	"end\n"
	"print(\"Done\\n\");"
	}
	,
	{
	"Fetch and load XML phonebook with curl"
	,
	"-- BASIC SETTINGS BLOCK\n"
	"\t-- where is XML phonebook placed on the server?\n"
	"\tlocal server_path = \"http://tomeko.net/software/SIPclient/howto/phonebook.xml?token=ABCDEFGH\"\n"
	"\t-- how to authorize to server (optional, may be empty)\n"
	"\tlocal server_auth = \"--insecure --anyauth --user admin:password\"\n"
	"-- END OF BASIC SETTINGS BLOCK\n"
	"\n"
	"--[[\n"
	"\tNote: expected XML structure:\n"
	"\t<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n"
	"\t<YealinkIPPhoneDirectory xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">\n"
	"\t\t<DirectoryEntry>\n"
	"\t\t\t<Name>abcdef ghijk</Name>\n"
	"\t\t\t<Telephone>123456789</Telephone>\n"
	"\t\t</DirectoryEntry>\n"
	"\t\t... other entries ...\n"
	"\t</YealinkIPPhoneDirectory>\n"
	"\t\n"
	"\txxxIPPhoneDirectory node name is not important.\n"
	"\tUp to 3 telephone numbers per directory entry are accepted.\n"
	"--]]\n"
	"\n"
	"function file_exists(name)\n"
	"   local f=io.open(name,\"r\")\n"
	"   if f~=nil then io.close(f) return true else return false end\n"
	"end\n"
	"\n"
	"-- let's use paths relative to exe location\n"
	"local filename = GetExeName()\n"
	"local index = string.find(filename:reverse(), \"\\\\\")\n"
	"local dir = string.sub(filename, 1, -index)\n"
	"local curl_exe = dir .. \"curl.exe\"\n"
	"local xml_file = dir .. \"phonebook.xml\"\n"
	"\n"
	"if file_exists(curl_exe) == false then\n"
	"\tShowMessage(\"This script requires curl.exe placed next to application executable\")\n"
	"\treturn\n"
	"end\n"
	"\n"
	"-- remove file from previous run before trying to download new one\n"
	"os.remove(xml_file)\n"
	"\n"
	"local args = \" -o \" .. xml_file .. \" \" .. server_path .. \" \" .. server_auth\n"
	"print(string.format(\"curl args: [%s]\\n\", args))\n"
	"local ret = ShellExecute(\"open\", curl_exe, args, nil, 0)\n"
	"print(string.format(\"curl ShellExecute return code: %d\\n\", ret))\n"
	"-- wait up to 5 seconds for download\n"
	"for i = 1, 10 do  -- Range includes both ends.\n"
	"\tif file_exists(xml_file) then\n"
	"\t\tbreak\n"
	"\tend\n"
	"\tif i == 10 then\n"
	"\t\tShowMessage(\"Failed to download XML phonebook\\n\")\n"
	"\t\tprint(\"Failed to download XML phonebook\\n\")\n"
	"\t\treturn\n"
	"\tend\n"
	"\tSleep(500)\n"
	"end\n"
	"\n"
	"-- MessageBox with MB_YESNO and question icon\n"
	"local res = MessageBox(\"Are you sure to overwrite current phonebook?\\r\\nCurrent contact entries would be lost.\",\n"
	"\t\"Overwrite phonebook?\", 4+32)\n"
	"if res ~= 6 then\n"
	"\treturn\n"
	"end\n"
	"\n"
	"local status = ReadXmlContacts(xml_file)\n"
	"if status == 0 then\n"
	"\tprint(string.format(\"Error %d reading XML contacts\\n\", status))\n"
	"else\n"
	"\tprint(\"XML contacts imported\\n\")\n"
	"end\n"
	}
	,
	{
	"Display ZRTP encryption state"
	,
	"-- \"on encryption state\" script,\n"
	"-- displaying ZRTP/SAS state on buttons\n"
	"\n"
	"local btn1Id = 15\t-- set this button configuration to 2 lines\n"
	"local btn2Id = 16\n"
	"-- end of settings\n"
	"\n"
	"local sessionId, zrtpActive, zrtpSas, zrtpCipher, zrtpSasVerified = GetZrtpState()\n"
	"\n"
	"print(string.format(\"Lua: ZRTP sessionId = %d, active = %d, SAS = %s, cipher = %s, verified = %d\\n\",\n"
	"\tsessionId, zrtpActive, zrtpSas, zrtpCipher, zrtpSasVerified))\n"
	"\n"
	"local line1 = \"ZRTP not active\"\n"
	"local line2 = \"\"\n"
	"local line3 = \"\"\n"
	"\n"
	"if zrtpActive == 1 then\n"
	"\tline1 = string.format(\"ZRTP SAS: %s\", zrtpSas)\n"
	"\tif zrtpSasVerified == 1 then\n"
	"\t\tline2 = \"VERIFIED\"\n"
	"\t\tSetButtonImage(btn1Id, \"lock_green.bmp\")\n"
	"\telse\n"
	"\t\tline2 = \"NOT verified\"\n"
	"\t\tSetButtonImage(btn1Id, \"lock_yellow.bmp\")\n"
	"\tend\n"
	"\tline3 = zrtpCipher\n"
	"else\n"
	"\tSetButtonImage(btn1Id, \"empty.bmp\")\n"
	"end\n"
	"\n"
	"SetButtonCaption(btn1Id, line1)\n"
	"SetButtonCaption2(btn1Id, line2)\n"
	"SetButtonCaption(btn2Id, line3)"
	}
};
