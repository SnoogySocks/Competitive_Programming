prod = ""
test = ""


def main():
    """
    2 pointers, left for next free space and right for file right most file block
    """
    og_inp = test
    inp = ""
    id = 0
    for i in range(0, len(og_inp), 2):
        if i + 1 < len(og_inp):
            inp += str(id) * int(og_inp[i]) + "." * int(og_inp[i + 1])
        else:
            inp += str(id) * int(og_inp[i])
        id += 1

    inp = list(inp)
    left = 0
    right = len(inp) - 1

    while left < right:
        if inp[left] != ".":
            left += 1
            continue
        if inp[right] == ".":
            right -= 1
            continue
        inp[left], inp[right] = inp[right], inp[left]
    print(inp)


test = """2333133121414131402"""

prod = """5855652869959230647675608291637275668414486693228034992584366068273525903934571348529451465147257374539168427356545693679759261610671714322648474095586556825287557320677423813021547854485874946736667039385979327144525520634761163363707424896132532417863261683734966483977632126992762954741474246947814445483092996968865178296462627941688956317673521062134430397045813112706633807769645584342346247229413943968127818514446884611682916273147230842494935954235261543088811750711230274813157945434570556056981095962611438638986720456485901029547645113496359271967465172781677283857516847220171140146810257515636398897840577666896782259348269926159261569353912714307517616138592185717274472193302658633763311820248339426422948880835255618766833357113756692475908253103132694813433051348065176025287120102011936713848934671718362128228313902577672391826650295335409436796426536855245329929631444853209793979532692563172897743526704899215243426352803119847990472589951589229874707180108718801610103232817843115898549272128213496421837591948674195721461529588299473824287462872572944724232365435355218479273248677558331667801680392768436613249185152199482013786167785655997956478157649991859450803080835520711043334062284972783317479485525439355114302995844045544265645992569356932181438692396890963596726199173253677768277948933253692283922113703241345460694418106072289537323086525765288480947183466242128946438479166224592979706418758828674498298348668219275787164986655985405767285093454932366722117627363923156788641626238662264731517114709694694446516795955038172652423611148649387340568662444543161083794524646791602131771943369987907352795911506423594089109316563480697240654567616452248885367329556438729195283030139727765049641460706578567854816880886141249087532977912040999787538647942751566137815181133345472358134783187485795479789052489034221721356986277624705388119410611428423124102296283267709997212255477776759689527412937495891867608252167780822853188573331566239653555361884850585421155416678019699047442836743976682960894752363823813763818568771042769825681816948045786296431660194542497714723635441014288465886163549929469129354841892049969484756530314338887811919251753645174873984381888374512363431524588533638322632636251024145118712658643227668384202086525980806833607771349722576376502336826743595813635475379795661026131575418346629418461390425187472329186322981492588824287137978524889010777017312854292847506876678591407881938930614336851731155334879343291919605497719157853261271129105812762024903287371996844679633733181939737854383210925768377834527095413976225555777054331030149415271328876634973054712535221274538988197961407852832968243367113990287774982967167447481071861378758295588923482222792724155761885557855319735098597992612235903443414213652320946634624746139753589718962423724375987054816030914188114783285415618568448181789688296565879693871919666870423427395128257285242849127383206121219593511828525055239274744499922840345484537668692381837338429434158587208283205275687142866670376158694266247194541643257532832411122381983455246371748353538646241463769172518710367674722586958927669316905980307059162936921575768913324795378634541091283447452538548179937922268354602148872386783624117581243738274550381133681781785246188932608984309258784596907521305131649444655569236928916172353559178154517740991468654462134695963871946118192612184874983546798397312740371340445512839960817756535348577023637918582744798060509551254724545275785035384181137073514296118879716224261085769184243838444871211295582410964570697475743731241784785719924773861937515228353853993512861633792929655349304267545418161833526920631942803723466922433516544698285568965230367620155162259316217658698098199925169073714452561545334497508234915563379174715660677120874031685185367357499265577840454012985059654956659553704330836059802673875145173123917943575770406579223781175636922336679394881670399239604550904264996971744251288234606179665215867449254655289079643634866081793530204955941190617210868842806265852796574160382115622725467566495685264956734171968074558474835593416223304627397515513021384784119275833377107887488955859064384180611265287150801280426593922975643465699345412485795854791973383075477539432784179097738618156818506928306960393524632196396271675629989629469652851557804073841971215526656995364257266956409523271483915211795468923021716380506923933818308960855374875072111182173289572159978787413520451324498522693031878396804455499953854039378824782982129095438584756922671195241386119493708447526578859498121736274049826393123748854219475222507279113377629250299730612060805111353085984793509832705667422494728893705631594288669446543973363299481958902244473374607184893145536715636221772249302750316244167246243681747599481287575669733262944412246822315618288452714444212490325932423510872933791878123528424767239074797951816037279110569366587629424739132374141093975628407847593153715674746555291756826396767284323827935210965918167293348185522380445823804470129161362778767916474780573390459775899216624915856745236097177910263411765172225921479311489270749712871780859425391386399622581189115522866665444080998892411914763479391568968419411781614190744724608339997944774291478599503425231741139928123026376234345835478455234074977330623223591437562869461422201976653090252547963929207176921933352248138491272085549421964153497578567075194874842768434482218813871392325194644948188371271990317779481447526136611928707453349692143781865479131838843599506788695998852537365075702919593354946174381184917061103419748139548720763388732265506731947421159534147925701733772481493676147265543595417686117182869532359094199558936845467949346942559166743533586045152410429181444381994563617558972729461612307450194677657737557389249445404717362936346650274429693117839457837615316998262175606564698662501163516483288664679184219925407650817291329121287131347619117189866522686181366174331811196243511315432879233877424372301264718723973292409973262528363281439263513224334280815313695449824315582672154199685931509827688651255044934734234938744941428888578391366230396770922518463654145980826010654743456386504195258079885216924798397649577362523842204254814656658613491343521447497324863430379572122117224089943329284157797393374017302675588164441152482043828218353419851925397749429135545471282462386451186584695618668765682944511196405639139065238559386868708060344351552181611226809757612229273144716663208781395074587250872860175787409737588758176735715539752777837541999644366098926798471670828177993541141076298780131623872197634037403921664372344783418496181375484174121511211016325216152540875875963766614889916075274578933656966326669640415279943883647676138069205753354944654795129748146683393694355618533455782695106648982236335986989054774139413817351077921932153273535188354715767423307732993757807291208031871399389361418842988211111564543587699352225447763099582330426542949468835879124418835566745543923366782440632436779345939176936370771135121845642416695622866126327488102482987093882277127420399850572068881065135469305034663947228265723756854859838977112260267763354096312636117630651468909599445645472162819778632321819825387452139632114278323919694121954789618994366547758659734335277465985813185960254551664727375154901930615223242047932083491948312121433767523396253459122840482525866010359029508044954949552253365879822856301094367028642060276726742133532942373338805397701918511824798625974030271758121150827250763929421453998751497513705136716789323911541455605875564959382329674420126024131673176942395086813931554651835825933932635833319592272754393144617974438190567062533415858251214019561937241053618511668332393922358389897817726375962785594533903421563528484556527614475657403041328093981260693478592462267427244449622579276939204678524034442629432196472561975018678349651290473779783196761241378097204053815541486899222751999685962170295329282039256449579428725751961644832676713532962557763420912955765790331642771253444619548062753669977255764964419396729451679549771141226128632647948059639619428944941694592144402460613560198271593915865142314584122655408622693378954059222245326494756072644411503364826687462550552018136320761446687724245755196979281756325045773383251416607141715678321292813244582555915536773879694033103884519012889567196742255579961766944912256977145069819871398110652360249856409367159137969452553556901173193657537526115642583270758862974310228742649171274333182531625892865790234299376591656829311362961539735327694919147115445734748938721233228053384917102461538658318557916062562997707327187139936811918143594725902978473641773137821562509081266441292332142855947954187391143879425545129270496861749497606397805123315444314126196613733553127458388764628845302092903976884789278410904172902749808973378233463819366837872081421571405846354566922194989036659172852898396024135574364078452633577024752393187361194799934535412731192534473265165391558290381742686139983221975530762596491447382062855048628275954973967135416377239340673947421334365733459122862764594079649374165917646390573369798096411821479856156478602929896497961415105520687062259169342623141614131064853823387168409185255895371386818965627647242159317789338119702661223858972140976060408349546021595225399547497869385021185993183377398065289760838536455182914186826540645323474326659382712723276723661627747467397662212854229414377231346896948943792561512979538140577213535489918993489825755814465288624626553634732518473383126336201619806091452523577561703560611058947040618316162828562622297543957140443546906469528429537328752840328936411499621126217527438337624153813144804522761492406182866590876177212590795928114357573274283244333932548925747897538378779222457344661529702348934369236410125984412032505464188157627286758743875645896370516345683612428891983320337969113912789311325525664019962044146838835384192368393890917836309150386446287943681135809650336015369082781553949981887196268944493886698353274942701376829351927551295112255946624917873840199222518698648142934135707567772614135247457852183733345514705172758845494227952591606655144919514796325529397979143735302353609281409193725637917953176787527380447949541457453253922687912675587990948736668274885992121634219360321953939890406712613192871215886819324425763697977799451091332199577682268938939651693351689636103274746026535698383987254731406145409777166069708392804622178722708878508049897222629235587010789041644721322438971567397783327745552387467368195243966910753086488023134886243819938147288792782766349775597417214656129664134623365335783319892696954491665641908769342320938857945696832959773129522012884144722054894690562349916826198518694517178033478824387942636825309058463755156460547231808288395942748774486591637664292412449949845470672710751767215462387054859421322132434859521531605412421563448338871816164585484746427483967838316536594420519750413992739363445071821682493661673324644744413278704671256043109133911842408472823463344628474871795673262135636337221713911593781573474787475998447853614766603060449324392782734828629672913162523971379673781963104777644134486893415272432471978278345094794968793373294080158277783582699726613324961463553413936496567436978874699360115048431593372285505520883081874358711370885352239021768487222771162187113641406330674373222991219849494392685913667491337724568661962477739863363343521488233350678792757412566626465481637540704858282746156535182690647881788659571283241482114210572195722373355745156354336116979841529733697033608082297092918673484061628427901055115972589721182960883591358668316262872916348412653990836445889165527532868357285372495337985114186571896133854097302174324780775926224893721935301859921271698068814593548513375248396739521038955464414774204886885295829981633927312631226959164186862763221598761097119687962255108729619523668876632417178939401780435121426856852124375985344259241566902837301715545011625135151361864299612182617221884178699014301448693398941948601268458958997252585159574291375216899446597336636875868256336995605359929220927818829159861293145264891555847755236253784892754493649438706613195486104116809776544161716570871490395797972215398717522449949838449594109567935280467145134262481147722453863296683711939176695252105669511110504748536868897486105146322475762635602175172225584430433370386223132412863483844185574671505832206410827967988284918386352369706014798261479751622310567297139253415470684014522872323789149578562343835357476585876769752914371949214075551414981554978017772730896927753568351626802075392281826082839228218183477521484144439136348159451719284620311450888444664575616125621995107659883858995978376958756125458891887482938897507554807724642578999314855588516541619978203519247697721164367374795039626842974983266322292250899493356156823393214082694428629169568679837011187665845022814013325728637022922068636544177643658698796534965319438866413173977257217982218546383543842865476979812450954316253854514454249564326461651536566619137457555572631298142297168125175343884680808014601714968234551143896145398334857244623965149212898772231695111579375624875078676124914213336427841872204429944927438119506124343253959299372912357258572229622393496487298494976243331817144574455437443551349879896383356179894917403885259275483993914772449233918115796427694220585755344334523360319884549314104521914341692527751530654359962771444154163580917697776810321178771730857521933058676835618097836595987236526615876230311245749436319338662078819972782886409271117228142562736490644489499467594690587117349850639148616082138654175453696984809543769972104751728864993436718945677088746624957765552384806314602853449550158447785742204861205435933472578115474168449452586589551471407365458727923019163257294649856770977957416284963521541913835385861159202897378021972058995049354094102460834957553035543990524188283027789239733175486934299910623046825898847525917450522288631670157511734459567048665183896595837746569237855830797769395279187047832677977740692887813974933661821256162040534998802546989662499453198852249555371586245772525465505062265630111077567124831158198462518365242431926598669319205916474621276971465322875883535749464917106970718423549818671636188774528160232251956563814619794667803667447792562771753281814514973428708564609559409734145511907740298673218476957086615731226530972435989242181592212533699031449290991229127824536264222998886752543443585277631762335595687014146869264528322763954760959051358977605855483593542119551741565146128283496931247030963844237982512041905238934128359389481691901850604782512367318331269919761051984411938643621078274464508314458465711292126693751791121680132072157279183818912531316710862283604142204413481352632677794696924757159334709082626782483247992116359960519061796168955584713624958118745298784136403865841044821344248788153350687454745643709497958510936151948444894387537972747415156448142752978161766622603841907915959974448015754860139666756970444022846084535234173840893729416590991449681962264752224832657269294812737339726869649016913164778884984557961153336890945150727458848044233414472488534529363079583033985270648160945583966291371556311763788257108727449169772846633291564545395994543811635971155915745932685397407940471511203753746050923882629732923176255243138985688346729464932918338090662063914813602272645471881927622942266083472796462624732033412755679679781089352878426489678047127393983565193897449052617057707521243714895496357691428813754164266953766749595183609485494529614012686771638984804487139649773155594385776274121989219032976347997642438930612970735670719232866166366962867819357774115818868173981463211324618944316196657965417773579097868925441676184955991826588187394525356716663223293834478865552812346713576924698485851780216364222215806762427077329783391684398879356570901511635482507415208738495892601378407655741518399846785180645650507684688125835555363755349515537640457026605873586725907248302995797419623032802550508033394212625421229128249729523673274542898399695110169742287343626148435388476784124920181844279042856556421910999818173249297113977342404583673475561167516145534310502199114380747713911318735934931247741795655145438757254147953513234977195199733686963377263620828773464488916540717118743345805115302729468483557121455218673767341115452123344853943325284264181842171943383332974693798349514980389738813858692346204756549053939126943119658123477524559148221136193813884798573741869093355048883670348626736179325962775885605272257341408520513793757840667154556066931255453147285198641217171993934775438115613193635871797041692691691366381940107120421559865064401485527792136366143375855292774416347097168644638653901295393875856383663892341340731572892911465715396355139590882729367460184790563470195755216326692641835070517369747034182955102371819333147779805155261456408798995864968669137970863336773847132058715257512785867984264282439876956256809697986490564395149558481575181345508045273865738091618059731036994790104410548031824437172862508070971392862594955084258946977590378178508234378244299196956637175719562846709575336624749123405783237535847115935086777392726563743893659120372942827073649857773739376442879146369414562542355559631759644489663824782851208780875525904683407473123624188623493990671726539460873380236399743523217892535214492712656226189227635981463046817735188427618231295996916793662712805279997144516094134645482966391012595863443054702348352728713626162536821546274564335285462397252048918079852424561468449254793934133617383087669935368024523792518924482871299911419942507276922269529112999168163211618763501123563340592550454244531611407519942857492674107018844639398841715890236575746219188663459562724280745933214847503426208948197561338719997571913921863920437715771714675571475751463355758741868387277055301696686551934485275382938112357020321118436775974937718492488041991563994846519519237369494246692114672552605816492496187242798517322914793462938288577998523419134680108247999099284815102691901843666051288574626782415470439387504476689016378220841052484457662419372612308098771039398218294242755641569315193365269220133028301169746095471087886867355581732755943446927772524697387662507896849448143817835018326715991157303970157649264227591950559433673289611310245043574653353319376773991483715327608247915611213115226326693629461485705883378165215099146291867235501780523659508842543089784617479116306493269260129518521828821528404317565816592928839035334695564767906372591998542973827935398088556410817519632772372150264670215327517612334175679316134380216682441050578476296927292889308296813093292422278991869385754621496865731112512653415076316357178887535332321136768828238458737026943224581223214346552091281730927999255131717280181195422787186093674386601356993810353785535053786964141314242249683119704096435580832137422846886217195671525149793340866712169519422722614017397948163733528849772716824310391538317642783632688187505717575140279749673451736250261987646815616313459588702779783923362387645950698188427716483232558478266858773035779491853990884995263967847478201252514236509193174476501711128571288445727410495657386733817945669615661440195813234730975979312223525969699946284441526174846493207659392334337560319572143380459084612164832321922947618180809290896165658712247722192953233150655541837526381519427725488863973713179614539922711557432471477792781027493787408177584463623367621330583678759340242940978519631825909819911514782643618687447290612351622646707591735041257185374852899831268188106034643264304027427562924690239158217073443113462189327148809864224472252684158386344921138785996616998985873863192039515467771130127486515893668990202122698228116647722785566947365677487769278980438957895456569944118051373650405883193246542190223158429529936290371331779414821012139441486392979579955133807764266437567190486587215252557940861347953274211957989716291326144491146619117267887722373182329281483647925881713463676151972862818160709373805796787789552"""

if __name__ == "__main__":
    main()
