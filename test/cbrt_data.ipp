#define SC_(x) static_cast<T>(BOOST_JOIN(x, L))
   static const boost::array<boost::array<T, 2>, 85> cbrt_data = {
      SC_(0.266297021326439287136622624529991298914e-12), SC_(0.1888421455001568264216782004847867296461e-37), 
      SC_(0.5920415525016708979677559909760020673275e-12), SC_(0.2075183790343685754527643464587844863336e-36), 
      SC_(0.155163989296047688526414276566356420517e-11), SC_(0.3735707037930203997047439019589434984292e-35), 
      SC_(0.326923297461201300961874949280172586441e-11), SC_(0.3494118359373226772153200620663814420149e-34), 
      SC_(0.3753785910581841633870681107509881258011e-11), SC_(0.5289425440452335470097113858122815653748e-34), 
      SC_(0.9579165585749116473834874341264367103577e-11), SC_(0.8789881934013975442181045034737061376284e-33), 
      SC_(0.1858167439361402273334533674642443656921e-10), SC_(0.6415854952683870221087767100660047169015e-32), 
      SC_(0.5449485307451595872407779097557067871094e-10), SC_(0.1618327663648593897188312867673509349544e-30), 
      SC_(0.6089519166696533147842274047434329986572e-10), SC_(0.2258130336429980668979991908229127823735e-30), 
      SC_(0.1337744776064297980155970435589551925659e-9), SC_(0.2393975994093713145816368117219309682822e-29), 
      SC_(0.2554458866654840676346793770790100097656e-9), SC_(0.1666850852333084475602734478539689292864e-28), 
      SC_(0.9285605062636648199259070679545402526855e-9), SC_(0.8006277238962806516943344887937136945761e-27), 
      SC_(0.1698227447555211711005540564656257629395e-8), SC_(0.4897647988639492837638733591590200680017e-26), 
      SC_(0.339355921141759608872234821319580078125e-8), SC_(0.3908105631910126517922937762400154556398e-25), 
      SC_(0.6313728651008432279922999441623687744141e-8), SC_(0.2516852352568191806987306088580024017075e-24), 
      SC_(0.8383264749056706932606175541877746582031e-8), SC_(0.5891685351226332190380177353564166513441e-24), 
      SC_(0.1962631124285962869180366396903991699219e-7), SC_(0.7559899905537899689665020666334853594435e-23), 
      SC_(0.5256384838503436185419559478759765625e-7), SC_(0.1452317136611010055610488165775172825142e-21), 
      SC_(0.116242290459922514855861663818359375e-6), SC_(0.1570697224733838212725464129330562874032e-20), 
      SC_(0.1776920584006802528165280818939208984375e-6), SC_(0.5610532144067232522265416539512374653302e-20), 
      SC_(0.246631174150024889968335628509521484375e-6), SC_(0.1500181866107243920079950771800422025379e-19), 
      SC_(0.7932688959044753573834896087646484375e-6), SC_(0.4991847137949555007936240315051986249607e-18), 
      SC_(0.1372093493046122603118419647216796875e-5), SC_(0.2583158853420963423689975850731860849521e-17), 
      SC_(0.214747751670074649155139923095703125e-5), SC_(0.9903435487644105337695875806797860570175e-17), 
      SC_(0.527022712049074470996856689453125e-5), SC_(0.1463821071995824977534730930446568768253e-15), 
      SC_(0.9233162927557714283466339111328125e-5), SC_(0.7871391209588633308733754268944773271037e-15), 
      SC_(0.269396477960981428623199462890625e-4), SC_(0.1955130454371024476239796923077328444099e-13), 
      SC_(0.3208058114978484809398651123046875e-4), SC_(0.3301616917426164412576388360054394990469e-13), 
      SC_(0.10957030463032424449920654296875e-3), SC_(0.1315462909319166691700161404508507291713e-11), 
      SC_(0.126518702018074691295623779296875e-3), SC_(0.2025182580848748191763613884783980516393e-11), 
      SC_(0.28976381872780621051788330078125e-3), SC_(0.2432945998183714075166971697772880334043e-10), 
      SC_(0.687857042066752910614013671875e-3), SC_(0.325457709339121122043443511174534212782e-9), 
      SC_(0.145484809763729572296142578125e-2), SC_(0.3079306732417723714591019095094197606751e-8), 
      SC_(0.2847635187208652496337890625e-2), SC_(0.2309154822558505456380682823926992940837e-7), 
      SC_(0.56468211114406585693359375e-2), SC_(0.1800578620431549562186637161391699604382e-6), 
      SC_(0.11621631681919097900390625e-1), SC_(0.1569644571431467249504618249826407884451e-5), 
      SC_(0.257236398756504058837890625e-1), SC_(0.1702147780446687692243218673184664750751e-4), 
      SC_(0.560617186129093170166015625e-1), SC_(0.1761972888887947511388016005088640519383e-3), 
      SC_(0.106835305690765380859375e0), SC_(0.1219394946966688262159601656951790626948e-2), 
      SC_(0.2401093542575836181640625e0), SC_(0.1384290502703277530255383713042680732253e-1), 
      SC_(0.438671648502349853515625e0), SC_(0.8441482026963079214835649797480515710291e-1), 
      SC_(0.903765499591827392578125e0), SC_(0.7381885006644863290177619358266650206879e0), 
      SC_(0.12760250568389892578125e1), SC_(0.2077674969235041602851348126190789145085e1), 
      SC_(0.3411548614501953125e1), SC_(0.3970586787024071934171232101107307244092e2), 
      SC_(0.671881103515625e1), SC_(0.3033034012472492122469702735543251037598e3), 
      SC_(0.802254772186279296875e1), SC_(0.5163413756551815056187668129261680860509e3), 
      SC_(0.264815673828125e2), SC_(0.1857081908850696527224499732255935668945e5), 
      SC_(0.54742523193359375e2), SC_(0.1640493194709731775162708800053223967552e6), 
      SC_(0.744071502685546875e2), SC_(0.4119495333434053702710286870569689199328e6), 
      SC_(0.210427001953125e3), SC_(0.9317607304574811554630286991596221923828e7), 
      SC_(0.286463409423828125e3), SC_(0.2350755546524705072036454112094361335039e8), 
      SC_(0.74548876953125e3), SC_(0.4143079969757992170052602887153625488281e9), 
      SC_(0.15343248291015625e4), SC_(0.361203491025739912996687053237110376358e10), 
      SC_(0.3632982421875e4), SC_(0.47950141115752447418868541717529296875e11), 
      SC_(0.8027111328125e4), SC_(0.517223035506184733219444751739501953125e12), 
      SC_(0.128921982421875e5), SC_(0.2142796483541738858568482100963592529297e13), 
      SC_(0.2196087890625e5), SC_(0.10591297122360160745680332183837890625e14), 
      SC_(0.614975859375e5), SC_(0.232580984311524292169094085693359375e15), 
      SC_(0.103892109375e6), SC_(0.1121366795544843797206878662109375e16), 
      SC_(0.2370011875e6), SC_(0.13312253103065122768310546875e17), 
      SC_(0.32081496875e6), SC_(0.33018996548382043793914794921875e17), 
      SC_(0.533606625e6), SC_(0.151937032114340403275390625e18), 
      SC_(0.1836336625e7), SC_(0.6192369863782824692494140625e19), 
      SC_(0.38194295e7), SC_(0.55717996837103384222375e20), 
      SC_(0.52642505e7), SC_(0.145884664571511666937625e21), 
      SC_(0.1527432e8), SC_(0.3563572958789165568e22), 
      SC_(0.25265768e8), SC_(0.16128631219129563064832e23), 
      SC_(0.6509808e8), SC_(0.275870040782346842112e24), 
      SC_(0.114023104e9), SC_(0.1482444961322159867428864e25), 
      SC_(0.189604896e9), SC_(0.6816299156208797501915136e25), 
      SC_(0.507585472e9), SC_(0.130775849541591501155074048e27), 
      SC_(0.764055936e9), SC_(0.446041700029835346607865856e27), 
      SC_(0.2103773184e10), SC_(0.9311008970618745805030293504e28), 
      SC_(0.3395078656e10), SC_(0.39133574711079901758452924416e29), 
      SC_(0.6645239808e10), SC_(0.293448554175562916132775002112e30), 
      SC_(0.9947638784e10), SC_(0.984373742549644225510117474304e30), 
      SC_(0.19561418752e11), SC_(0.7485159350422880041966143275008e31), 
      SC_(0.60532621312e11), SC_(0.221803524649682352197867382243328e33), 
      SC_(0.78978883584e11), SC_(0.492643743012832976593364088520704e33), 
      SC_(0.169071362048e12), SC_(0.4832926096640938859567595590254592e34), 
      SC_(0.345661243392e12), SC_(0.41300191319644612608733712417292288e35), 
      SC_(0.994912108544e12), SC_(0.984813853841992339417900620588253184e36), 
      SC_(0.2023890092032e13), SC_(0.8290119158315231036253469850906656768e37), 
      SC_(0.4372805189632e13), SC_(0.83614267463479414022236113855701843968e38), 
      SC_(0.5516391612416e13), SC_(0.167866976532732026957407327191402807296e39), 
   };
#undef SC_

