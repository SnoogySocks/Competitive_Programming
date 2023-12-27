import sys
from icecream import ic
from collections import deque
from dataclasses import dataclass
from typing import Tuple
import re
from tqdm import tqdm
from math import gcd

# Import the heap functions from python library
from heapq import heappush, heappop, heapify


def p2():
    global arr
    og = list(map(lambda x: list(x), arr.copy()))
    arr = list(map(lambda x: list(map(int, x)), arr))

    dirs = {
        ">": (0, 1),
        "<": (0, -1),
        "^": (-1, 0),
        "v": (1, 0),
    }

    backwords = {
        ">": "<",
        "<": ">",
        "^": "v",
        "v": "^"
    }

    # coords, direction, steps remaining
    q = MinHeap()
    dis = dict()
    for d in [">", "<", "v", "^"]:
        dis[(0, 0, d)] = (0, 1, d)

    for d in [">", "v"]:
        dr, dc = dirs[d]
        # dis[(dr, dc, d)] = (arr[0][0]+arr[dr][dc], 1)
        # q.insertKey((dis[(dr, dc, d)], dr, dc, d))
        nw = sum(arr[dr*i][dc*i] for i in range(1, 4) if in_bounds(dr*i, dc*i))
        n_acc_d = d*4
        for step in range(4, 11):
            r, c = list(map(lambda x: x*step, dirs[d]))
            if not in_bounds(r, c):
                continue

            nw += arr[r][c]

            dis[(r, c, d)] = (nw, step, n_acc_d+d)
            q.insertKey((dis[(r, c, d)], r, c, d))

    while len(q)!=0:
        (cw, cstep, acc_d), cr, cc, cdir = q.extractMin()

        if (cw, cstep, acc_d) > dis[(cr, cc, cdir)]:
            continue

        for d in [">", "v", "<", "^"]:
            if d==cdir or backwords[cdir]==d:
                continue

            dr, dc = dirs[d]
            nw = cw+sum(arr[cr+dr*i][cc+dc*i] for i in range(1, 4) if in_bounds(cr+dr*i, cc+dc*i))
            n_acc_d = acc_d
            for step in range(4, 11):
                drr, dcc = list(map(lambda x: x*step, dirs[d]))
                nr, nc = cr+drr, cc+dcc
                if not in_bounds(nr, nc):
                    continue

                nw += arr[nr][nc]
                n_acc_d += d

                ndis = (nw, step, n_acc_d)
                if (nr, nc, d) in dis and ndis>=dis[(nr, nc, d)]:
                    continue

                # ic(ndis, nr, nc, d)
                dis[(nr, nc, d)] = ndis
                q.insertKey((dis[(nr, nc, d)], nr, nc, d))

    ans = min(dis[(len(arr)-1, len(arr[0])-1, d)] for d in [">", "v"])
    ic(ans)

    # sr, sc, path = ans
    # og[0][0] = path[0]
    # cur = (0, 0)
    # for i in range(1, len(path)):
    #     cr, cc = cur
    #     assert in_bounds(cr, cc)
    #     dr, dc = dirs[path[i]]
    #     r, c = cr+dr, cc+dc
    #     cur = (r, c)
    #     og[cr][cc] = path[i]
    #     ic(path[i], og)

    # ic(og)
    # ic(dis, ans)


def in_bounds(r, c):
    return 0<=r<len(arr) and 0<=c<len(arr[0])


def p1():
    global arr
    og = list(map(lambda x: list(x), arr.copy()))
    arr = list(map(lambda x: list(map(int, x)), arr))

    dirs = {
        ">": (0, 1),
        "<": (0, -1),
        "^": (-1, 0),
        "v": (1, 0),
    }

    backwords = {
        ">": "<",
        "<": ">",
        "^": "v",
        "v": "^"
    }

    # coords, direction, steps remaining
    q = MinHeap()
    dis = dict()
    for d in [">", "<", "v", "^"]:
        dis[(0, 0, d)] = (0, 1, d)

    for d in [">", "v"]:
        dr, dc = dirs[d]
        # dis[(dr, dc, d)] = (arr[0][0]+arr[dr][dc], 1)
        # q.insertKey((dis[(dr, dc, d)], dr, dc, d))
        nw = dis[(0, 0, d)][0]
        for step in range(1, 4):
            r, c = list(map(lambda x: x*step, dirs[d]))
            if not in_bounds(r, c):
                continue

            nw += arr[r][c]

            dis[(r, c, d)] = (nw, step, dis[(r-dr, c-dc, d)][2]+d)
            q.insertKey((dis[(r, c, d)], r, c, d))

    while len(q)!=0:
        (cw, cstep, acc_d), cr, cc, cdir = q.extractMin()

        if (cw, cstep, acc_d) > dis[(cr, cc, cdir)]:
            continue

        for d in [">", "v", "<", "^"]:
            if d==cdir or backwords[cdir]==d:
                continue

            dr, dc = dirs[d]
            nw = cw
            n_acc_d = acc_d
            for step in range(1, 4):
                drr, dcc = list(map(lambda x: x*step, dirs[d]))
                nr, nc = cr+drr, cc+dcc
                if not in_bounds(nr, nc):
                    continue

                nw += arr[nr][nc]
                n_acc_d += d

                ndis = (nw, step, n_acc_d)
                if (nr, nc, d) in dis and ndis>=dis[(nr, nc, d)]:
                    continue

                # ic(ndis, nr, nc, d)
                dis[(nr, nc, d)] = ndis
                q.insertKey((dis[(nr, nc, d)], nr, nc, d))

    ans = min(dis[(len(arr)-1, len(arr[0])-1, d)] for d in [">", "v"])
    ic(ans)

    # sr, sc, path = ans
    # og[0][0] = path[0]
    # cur = (0, 0)
    # for i in range(1, len(path)):
    #     cr, cc = cur
    #     assert in_bounds(cr, cc)
    #     dr, dc = dirs[path[i]]
    #     r, c = cr+dr, cc+dc
    #     cur = (r, c)
    #     og[cr][cc] = path[i]
    #     ic(path[i], og)

    # ic(og)
    # ic(dis, ans)


def main():
    assert len(sys.argv) == 3
    sys.setrecursionlimit(5000)
    TEST_INPUT_STATE = sys.argv[2]
    TEST_STATE = sys.argv[1]

    if TEST_INPUT_STATE == "test":
        inps = tests
    if TEST_INPUT_STATE == "prod":
        inps = prod

    global arr
    for inp in inps:
        arr = [s.strip() for s in inp.split("\n")[1:-1]]
        if TEST_STATE == "p1":
            p1()
        elif TEST_STATE == "p2":
            p2()


# A Python program to demonstrate common binary heap operations

# heappop - pop and return the smallest element from heap
# heappush - push the value item onto the heap, maintaining
#             heap invarient
# heapify - transform list into heap, in place, in linear time

# A class for Min Heap
class MinHeap:

    # Constructor to initialize a heap
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i-1)/2

    # Inserts a new key 'k'
    def insertKey(self, k):
        heappush(self.heap, k)

    # Decrease value of key at index 'i' to new_val
    # It is assumed that new_val is smaller than heap[i]
    def decreaseKey(self, i, new_val):
        self.heap[i]  = new_val
        while(i != 0 and self.heap[self.parent(i)] > self.heap[i]):
            # Swap heap[i] with heap[parent(i)]
            self.heap[i] , self.heap[self.parent(i)] = (
            self.heap[self.parent(i)], self.heap[i])

    # Method to remove minium element from min heap
    def extractMin(self):
        return heappop(self.heap)

    # This functon deletes key at index i. It first reduces
    # value to minus infinite and then calls extractMin()
    def deleteKey(self, i):
        self.decreaseKey(i, float("-inf"))
        self.extractMin()

    # Get the minimum element from the heap
    def getMin(self):
        return self.heap[0]

    def __len__(self):
        return len(self.heap)


tests = [
"""
123
234
345
""",
"""
2413432311323
3215453535623
3255245654254
3446585845452
4546657867536
1438598798454
4457876987766
3637877979653
4654967986887
4564679986453
1224686865563
2546548887735
4322674655533
""",
]


prod = [
"""
234224446511352516455541135325314531634727166622143245766763225647632451765767416671144613511443236745711614774573513156356624145646555245245
212322435323514544553641367363253666612634513752244741772464882587283261185481663234173466116432233354744314723223443226616466142554244615221
154152563214532244465661223532752765765536752111625474845637887368476118636565287714213441214743556752653777372231566152665555565542223661132
525351545121363546115654612131231624245142132533745467388828681775578761357857745526314153768275636564561457571644657123363231241411332326452
522114653525543314412571231775375576521726522526173787746687625733216838476458572461735582761552332354146473113664476437323544256213653465312
443461111453464425134533263471641143456312642513254553134486255281263333132627453587376148513841638112145441447467121325743662524522222564561
121561242535123615432415761156744117343342787528337632685333272267485453814315762514375344282355222836135147727216735114447424342623145611115
252364155625164632364226342712756457722482166171424514185723628628385346554137328865165246138577236216314644645345152746244165463554263431662
526235655521461214532363651147275227312867814244778334561422454447813222487123182687265214271615331836735221433453425273364571222611316513141
225613523613165246477246751254654753681146264113713375321815133313787726311628571367126163638537824746257617322231667614624625234561431115155
616563433623453266134751445441374188283828448111241335241358271167617623631466526171652755173476473628624453325743534253553643215315665446664
362454134346111664574275576134363881382835554627886265337151312271626774356824843526711868556657745186332348785164631216416322634341234413516
624336624532333445671425266574645652272115613176467134887187742741469411579948718446242474241162354716284775774771647436742135325654335522566
132343424642761631543123634645772441446845427562772253584555613884465971938339166852115365255171177614564262127653746766446335143674613123433
535535523125362516275233147278361816341145714212373261429933467545965438848556428291619597711642148812153188248135232621151315233111352664626
315343656233125631622636314237357726527844653166554352554933575475553534566517335193254452417712415515324211548464562731652665511511512253654
245346621476366211755722344353743773657654226437321698155539423337438917574628428885639646215654518165726815413468712371547455776676132656243
414551316523274412372317175216327536416562753587542796888542934873711444595783331864282184886161875526523451851636436814722427114752445365531
562663143716616766467664564174363675132344384574777184479621561743232265434434231935369454446266975363876764334367855477613562617435121536253
333251744334237531433255753676546564133517262375329868342183881735133142953538769718862388827716173671453554811618816365677225577565111344134
512661663126517112325472217657543714745735553916577177949218283171176592187821211794496862411899576961517632242138512638331655164553266254665
244227644642536633766824571648522446857399591619871385492483166519243226118878624437768759799251983569643248154211166213445165777234666464641
324626331157265155157741667232871854422398384135566321537312449412339576552296252386497358829297514485667786624681566152245124765225523676712
235175461263227616717532311838821361526356926784576534178895547893938757513753139533558433561823156636393612812576511244357754316122434344372
454551271165612352163544844775382463429373136432582264346514888937676299395477556354793172118843462717455359334461235517642641433143315324673
416777235642161515516777522231658872775586436867518275137556927363464472797246945994621431276264617637494126252357632267636242572624251211772
575512561173237458478861338838441972978863848866185494238353553765253724428398463789383193574682229233161522986384788872722638445261673456274
432461231356112282843327267713475289479639627883637285329736352263523668944488476829536699931496583343898715537781226624225246115566447124214
252374211644248241181722875581971815998627361756281283355698847254989548635729983476322282385822532133147958951348772444685135673375547112111
744751517727144286855173182671674768351646816849663957283526244234354549743269888853236478424856479232256548691921754871261651632127374773326
347346713512748345888728346126596745814927293432346969427775577329297989639265922864632254289837722247933768912811567686168868843565656653217
263525422653617877331388151423687859343291276798643458639499872848588365842774627258743984789859872779948615316313852576628322412161271277416
277113175314438882726783556873396413855231169332222256398724594787499249972764694354548667347376366499328522189845971158626881316477422427223
245677355173582872431581449915548919571284795989627935422527427683596825792637987238353427594946982728418324518961279422112637337471142624163
267354316271177145465486649797625579633264878858779569537863652839985535626474226832335689299483588652398435544987621954432653625233147551173
377654346388462182388671459629376356923778826739354739567967376956676676475646775265329749698236263866938779859135684496138268675617576414665
771754626518631562445589178277977182765474439572987274739268222633497565479748389525293666578349426979961779336492775716647444226316124512655
232677165584621238512574545123333857973584553287462722332937834949437747996976746325689466574343999457446979149255222712874245157455322253161
571517331668313885733787433842981235372267297852833756684977873598543647564674339786482286889793593647935699321881725769461878284244721524126
532213162631227782434387883462491267556949225489659973844878533548853853785345757484536544846887554546273496481544598171122555452171867424543
211233451885228341726955645125112515585522746724447664543555776843449658349758686847933942944526824425798375866989587953863528851883575732257
461673283885572418721956824884534117853785825835245753536773798749846489855758979583477964976962528886524484291832616559944782258142811254113
551745567215173881717465384242285886475968986496477846444344838468847889563747683844699878434799647432635288748175368314713153814671171583316
433136211825262278825549652223761352636945979765397635476539984848657445443793375637456955348734622577948439847242476876339788672616754773222
341476444277473656149363138182378655456396734378335886793793873964643865998394976458373365937348733496289268894571554998394665558346517171532
725148333332238721464119665117194535376789327288965665679644644849889355359637636575364545538834985277623753633296688395633394345638365141251
237733752121746652195652112461855435637442435369468347339547836585458374859445746866355579938788624834422823493824725835514514145252633111217
742173484483385623323737178513575879868346925664777384638899835397536798453557999739935988976993788948756778953321354545976365682473315831873
256162553288246862454931669768823755967327448644574654865398338646594775785845734838346993343964353956596849355391873252421731271378154158416
647611143287731788875665377547398763778946959366367468535776755896579896667774888566654676466854465465234899323699225115696914378788782261761
761584483441614646496258979977773637988422437459976888934949955888448847978846588785393643933759698533938252289955483438238344821416112135431
131653441781113528654819832795793723536858747568374353586645585579456598545786878747735688386453798489973229893572541932211763522545754288432
351435431774587738542714531244945446233565793677477556657866475985655674989947669744744833498483568563857529348972253818416477686632645617222
474833573242841478256345936362392996854889844895586943335546985765757966878465665597669844578549484969635755547986436374943152167431585427724
668874184642473919751153976864969787866297896464737784547795946547569494576846995766756738548589494956528446584679438364951963249487138322523
528725624761152327819595517454868825557798544787777668748684886944587886875784597564494955345468545557764664683692997796272664459383234468271
177437148884516181535654988786999739996678493436643755697498977987775798565946898889884577867886763979792697332792946798841654853731628523744
442361247181141182933518157353757765727538878755858474557755996494864876969578594588669746866956689553358636896564543761518884527661143322531
375251227671244772949529497956653786555839448577749749769654888645574864787864998687767898555567899563635343933337472963879652274874388156822
528858226558578556821285155698996484679446995674879994687857876767595796446896759794489559979683384366869269434996895238567686659384214676447
136263238663856349766786373944888986784864369665885574949979597644468788658685799698986768794337593377696744756996756723172285446462245728465
767223256145565586897633287358249238285396779986757478994569764845577997689589457955686858855463663485667696392425465253428235418156226256151
437775176261364587767849429958878855345499435634376668774568949777568776887597748587485784897759749468984385667483598878343637736486713363811
214436474531345195792918567557532395448683458888896855779677697985867879959577998686867849558878938333959823725857345712255479596583727545833
414758443545213224319231493927398357335449653347797747757849687757596755885966686654846554689534984885555933248756559948356274139793432274843
464165873353938783791212759986898624337359999933665694495697877758789989578656876878868668474776699744579462679968668748268121718868115527214
281418552824348619758435738856526466847658575477565769565589797978678988676857877567445988989677469469538539829686463432572149939875173433145
174745572187172734825327438492543924575974589439498578765746598899767757988956855785496888877558459337747787694597297962228175473327338484777
423561863457895625429957337935554753395958554744554766885876588597758565895778566777687765574496986947556946637957739771361764529851733731778
876464625342977414342158652568734625934775657348846666744756579888578769688896976589767479895447583959567439826398946571623698744513387161862
861524435137586438869557842356734487944663935494599899799687965887979778565885959677497645587789989738875346495894362792944358783326623864717
252162437585483184143333563589379384846535454987886746764794958895655596556598777898799798677965837694666889622667872721462528751722864574531
511835467648858463122855834823235252594346993435979575697859585787856759886889685959994484765896644589375446245555422761754213596566133655786
185767163152935413185483934749657393776997338375844977976999877696777885767957658878599568766597959677644694337432859589864618184367464663237
168352331587493643594282544262874648433436948954476859757786685998985686877996689784845779978789888367567753568222364473887654656831873518886
313847575343358369622475425393596573693553553475664966456468988556596966579695897966647774879958544966675886284764996391981912412686273864525
373283716753197975283815795263553242688656659394667497869488778578655597989779778678966748859587549566998575497752466827394482447342838558687
836764585368366932293427479724823928799384596667899864645965898686987768975986988968598745579674388483936764685998592549762341336622547118571
247882245157662991361453943787554369377534987474547945644678695868855779857988867745865484878656354465456887234799955694478693551968514531566
571745824313431258854696432362643266678736763794959846494594744699969798768675654768746549576975777495396784569274894757254671157467263337537
275382782161696438145337579287764348363465957967784446484488955786985868887786764645484487445587897476735675249884843668512937819945782888438
217118865135294215886286244356928338247374968985465849584876446499965788598767897674866859457883995589468837868668764946672362581157458453223
161762616588571177211757624985496884768757663548899465646697995957588866885879774694559595869535679899358587552833589569798385633683824477376
615738185278515945148931826499354984928337698948544695886769645955595854794467855979769766459398866945859864537966827295362723756851454667378
463858275648821252653439544785654984695649693834339356684947566497785794859445899577455595969447784764465834993256959555194238234428274766576
338526824731316778299327722883284957232494386489595686444589559979778766677669449569784497684534633973373369673487954545216614341354486546688
632663341188217371767432175779672344263585379573973398998568459976764465847449488495965985856776398569564967592352275586132667341372774582144
325327418886431163516783134822583489572569383579476977848996495497666599599859986968485869759576557439658784226222552141432856567122715223315
175626222822669261225782114655635489383869379798566579878595947674675967475666487769897769377955995976854626825643456128323475267184368481358
521323357458161622944913168548772657649499844398453597795696968688464675479887784797895439499343878895935872889348688549327979526282321534555
657685352472514713663558244566679583882284594596694645799956565484574989698659844865945858348354669445944379478334867693834555938122537147716
141488171222833987755851223559928238636427963876857645886446476578795976467947777658558593773699579953767927838358486398739277326554475442265
412228731552363175889135217262652782645923285376439895389973585975758446984555465573895895596848488625986957427972975581749123637831761353381
617657426244228783349859988279727555729665575366666558833739986957676488955584699954955898855544586592226593279252313954949991982333435345743
563442734644636355662243521542523458337282367653649638884398879578985456684668653974966989874646697672782569953496336899511812338637762232843
123663572448778825513745536862954443659747664546953765778543734458335968973986374649983369665896784968524444424982732395492581267433746863823
376137586674633422247188654418472528946595834784945567566555865934666645875353358387573569744966475669534496983426926432416113218734182381755
536512416727716348573211189799286479936666386849438359939695539833385979538849989684875449876478945525759697657772175829389678813764551371776
363762235558516186995537179287137923595878379285484597469333538564595445667659395973583984664463972748945252996983429483238836425782225683314
411567166341374665512465714148135639464364664678858934748484833547993355358584697736779897843654377746544924667542949676594752322771766675517
266463442531538515324415365824823343796529839682437757497647479747465599445594584493697737967736967359439396723339167681517716552748316854546
633435562174817662819725623494342626327278792489579386934644484644498873873868948379464469982422437757864357965387175465818761476538223856362
271474173321581181863484657984524328824246435927523486584385459438749874835766639984498748222533995293879343664866751243411775711247686463445
172532467668431552657851134947876991864446634488763265888467474978838337773547939668583324433527566227443264838614694858513778615328843151631
435124444672478328857526275643761216658887846797547794956838949975773449586349935373834828857947226423265395741533458688623884763564786266637
527444267343572326138358326494265251515445724778664453589368769497437586989568786664953228358866755867323355671375222573553884523886831565716
232337242156786171451425413151143419785995526686499884629874972235468659879944847389624798358326959692735154455522549119836424612438782565661
525324767315186524221162635561617576129944485347978995887487338596577476435565783459232524539973955777662639947226566144181176541648162561146
374312313453312672658751476534281367282451989647686494962485282847957484876677835643636882948663369983595636223946539735662847525583337135237
657725674341517314457517872977437584615635962693597374837933993832832447824828324257766543384427365687137896483877556522741157743758623147235
372771127456775223357761286248823729625469464727389249234268533582598285959338783389942977743988349247557954865442128257123555573555665712277
515335142747587238136873274317921898723494161257278958799238797628727856354779782864486553256846279834971983684475434414142845851554475257543
211654411663544148312323264167279678992961187448639679752372227475263666927434479985957627522647248923252666532949661642868618327463727133563
575353243265174755577627351259572411237675399671852542638477264597378258822786682357658459859297678637384567437676676788158223637447654324241
344563236652472466162868335152512983162251322752221983569455659558997445574957993598937383382183666629133836889984451477661412435246555225437
223437426514546151342863435541278568599978275856575243983899862339557836373398238542432233847936295436294528611618584858851828155673555363673
565267721125431772222258467541455975845395974995469284982657533426324232877942832789383857469751548722226928556847584174234736857324544174152
365667545462772453144622182647818785365195919574971662635979473568846497942633855587497515748764182696877559548732422754666482313545142511135
223136324577276227545366164446137136233877236897773326422143147259726566925933512459523473114954553466232232776114255426767556663344523436615
424657666415524464138833867462574616883893546743855815271583277657111922247498683683766485168765665542848175476622462668832226126115112332563
265116573351654653441425345433343264833724888898842991923143888271879144828857645268426289642628397318681665422186228823688656343674532547354
361613244731346314646327483436567238222652636787896548679217398257817686662528758385799662244638311167665784234841576282126433564612123217133
566364152131725364444145773355671731247157114363871741697496591525191862316358584851473882379619342855334363254135373643731231155715651443244
111256566517565774627311267233356113376155286417849697544313299988665623767484297173881389848752358814348845512636815363336672474277513532513
443415375565151466272566277284217717116514368712686791634141681571148667847889493663177485648178298411228854887663854727367737311167552216516
346244164371664363576256455768247347527684384744154279982116974879397294334515785175512974663863243245154443634883878735143151637137165135251
245632136545644623126337434764381666623631161252826613527253566475798597166214319621828796869725132868176464361433567372227351272445425655651
216516466233275546255724611446138854335312811112351914676757679869148379278132566316591751417332726833815854582571241637211356745616512565456
535111311616623261131633537112222351656224611568521375539855193624971352427634275747912521578651888765337513854385447315451356342663443241522
523564135532151626121315326541456154526371646221237578445836513495426246777258961949148742547244632878273363385166566742534466366314635143152
252234333515321424364621267324383352132525716557115147854544432871484997689117152888713844268647861353255157166367574546234537757321331262556
145425651236623323273646167464663122164851147643457787247461125283223626312635725718725441162657418176341734786544172723625253573163221641535
153544115353616111234322326252465422638432222836276323413433218484851271551611574588585845524146471163748483365626544317657137523214565531664
142454216141535536457677212613665411757451356675835477342741324113281212655366244462261387532622858861721373636645712474172445746411324252141
544366355562212456323663575657652624265473162613232765146888652425214745741187347176246123657843165474374431111567224417353336461634551513361
162431526333225556252567676426362353124153634115551752877846847315344364261273381582556742168434542853227112722624762136771622135152112255361
545211215455544513544364765155651334654454375184885815375682761478165137382187757661532864566263223816742121372337523621743544464511511654416
323113161515166212124556631324747676271655372663781844847848363158431826435478212561154784384763281335313764523453446537353211111351216512414
312123524165526161625112775375335447714743527628876182525825513257478674653831351253148186847312267555532675463177543242652353436331666156244
355325535435126443145256221374357314335277645253556148534766883344445466258512416725216676611327231436111554244566637214312626234251335633244
452513136443331344523212472543322532423675742651453274312732754834486467728123135388734127674473266575113615746472746566662242413522623644335
"""
]


if __name__ == "__main__":
    main()
