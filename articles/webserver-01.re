= Webサーバの基本

Android端末を有効活用する上では、インターネット、あるいはクラウド、そしてそこにあるサーバについて理解し、
それらと通信することが欠かせません。

本章では、Android端末の世界から少し離れ、Webサーバを取り巻く世界を概観してみます。
Webサーバとは「Web」の「サーバ」ですから、
この2つの言葉を取り巻く状況を理解すれば本章の内容が理解できたことになります。

まずサーバから行きましょう。

== クライアント・サーバ・モデル

サーバは英語でserverと書きます。
日本語でも、例えば「ジュースサーバ」「ビールサーバ」といった表現で登場します。
@<fn>{server}

//footnote[server][英語名詞であるserverに対応する動詞（「〜する」）はserveです。これは「〜に仕える」「〜のために働く」という意味です。serverのコンピュータ関連の用語ではない本来の意味は「給仕人」「接客係」です。ちなみに給仕の読みは「きゅうじ」であって「きゅうし」ではありません。]

#@warn(TODO: 「ジュースサーバ」の画像が著作権フリーの画像ではない可能性)

//image[juiceserver][ジュースサーバー]{
//}

「ジュースサーバ」は相手にジュースを提供します。
Webサーバは間違いを承知でしごく簡潔に言えば「Webページを返すサーバ」です。@<fn>{web_server_returns_others}

//footnote[web_server_returns][この一言では正確でないから、本章があります。]

WebブラウザやAndroid端末は、サーバから見て「クライアント」です。
通常のAndroidアプリを作る限り、「Webサーバから見てAndroid端末やアプリがクライアントである」と考えてしまって構いません。

クライアントであるAndroid端末は、例えばWebブラウザを経由してWebサーバに情報を取りにいきます。
この場合、ざっくりと言えば

 * Android端末はクライアントとしてサーバにデータを取りに行く
 * サーバはクライアントの要求を受け取り、要求に見合ったデータを返す

という作業が発生します。

Webにおいては、WebブラウザやAndroidアプリからWebサーバへWebページなどを「リクエスト」し、Webサーバが「レスポンス」を返します。
requestは「要求」を意味する英単語で、responseは「返答」の英単語です。

WebサーバがAndroid端末に接続してくるということは通常ありません。
「リクエスト」は常にAndroid端末、アプリが行い、「レスポンス」Webサーバが行います。

より一般的に、データを要求する側をクライアント、返答をする側をサーバと呼びます。
「クライアント・サーバモデル」という、インターネット・クラウドで非常に一般的なモデル（考え方）の一つです。

本章を通じて考えていく「AndroidとWeb」の関係では、サーバとクライアントの関係が逆転することはまずありません。
しかしクライアントとサーバ一という役割一般について言えば、逆転は起こりえます。

Webサーバからはちょっと離れて、複数のAndroid端末間でWiFi経由で対戦ゲームを行うケースを考えましょう。
多くのAndroid端末はクライアントですが、どれか一つはサーバになり、その他の端末からの接続を待つのが一般的です。@<fn>{maxio_cart}

//footnote[maxio_cart][携帯ゲーム機のカートゲームなどを想像してみると少し分かりやすいかも。]

まず、サーバ側がゲームを行うための「部屋」を作り、その他の端末の接続を待ちます。
その他の端末はしばしば「ホスト」とも呼ばれるそのサーバへ、クライアントとして接続します。
プレイヤー全員が揃った段階で、ゲームを開始します。

上記のゲーム1プレイが終わった後、別の端末がサーバもしくは「ホスト」の役割は行うこともありえます。
例えばさきほどホストだった人が自宅の用事で帰宅しても、
別の人がホストをすれば同じゲームを一人少ない状態で行うことが出来るかもしれません。
このとき、その別の端末が今度はサーバで、さきほどサーバだった端末はクライアントとなります。

=== P2Pという別のモデル

クライアント・サーバモデルとは別のモデル（考え方）にP2P（ピアツーピア, Peer to Peer）というものもあります。

例えば、電話を考えてみます。
電話をかける側とうける側という立ち位置で見ると、どちらがどちらに電話をかけても問題はありません。
「クライアント・サーバモデル」のように、どちらかが常に待ち受けている必要はないのです。
インターネット電話アプリのSkypeでもそれは似ていて、
相手と通話する際にはどちらからどちらに繋げる（リクエストを投げる）こともできます。

このモデルでは、データを要求する側と提供する側が柔軟に入れ替わるため、どちらがサーバともクライアントとも言えないような通信の仕方をします。
実際の生活でも、インターネット上でも、必ずしも「サーバ・クライアントモデル」が対話を行う唯一のモデル（考え方）ではない、と理解してもらえれば十分です。
@<fn>{server_exists}

Peerは「同僚」といった意味の英語です。
ServerがClientにServe（仕える）という非対称の関係を明確に意図しているのに対して、Peerは通信相手同士が同格であることが明確になっています。

//footnote[server_exists][実際にはかける相手を特定する必要がありますから、電話もSkypeも「交換手」に相当するサーバが存在しなければ成り立ちません。また、一回限りの通信を見ると、最初の接続を受け入れる側と接続しに行く側がいるという意味では、P2Pはクライアントとサーバをとっかえひっかえしている、という見方も出来ます。]

== プロトコルについて学ぶ
=== 相手がいるならルールが必要

相手がいなければ、自分でルールを決めてしまうことが出来ます。

「このデータはHogeHogeClassが持つ」といったルールを途中で変えて、
HogeHogeClassを継承したHogePostClassを新たに実装しても、
ユーザに見えない範囲では文句を言われることはあまりありません。
自分がそれを守れば良いのです。

しかし「クライアント・サーバモデル」や「P2P」のように相手がいる場合、
世界中に分散しているサーバ、人々と通信します。
「ネットワーク」の章でも学んだ通り、相手がいる場合には何らかのルール、つまり「プロトコル」(protocol)が必要です。

インターネットに関する技術的な話を除くと、国家間の外交に関するニュース等で「プロトコル」という言葉を散見する印象を筆者は持ちます。
その場合は「外交儀礼」という意味で、例えば他国の王族をもてなす際には一定の手順、すなわちプロトコルを踏まえるのがならわしです。
破ると、場合によっては外交問題になります。

=== 相手がいる実世界の例: スーパーに梅干しの在庫を問い合わせる

仮想のスーパー「なるえつ」に「大山の梅干し」の在庫があるかを電話で確認する例を考えてみます。

日本のスーパーに対して梅干しを電話問い合わせする場合、
電話番号を入力して相手につながってからは大まかに以下のような流れになるでしょう。

 * （客）（電話をかけて繋げる）「もしもーし」
 * （店）「はい、スーパーなるえつです」
 * （客）「名前も名乗らぬ客です。大山の梅干しはありますか」
 * （店）「少々お待ちください（少し時間を置く）はい、在庫はあります。」
 * （客）「ありがとうございます」（電話を切る）

自然といえば自然な流れです。
ここでやりとりされている情報を分解すると、以下のようになります。
なおこの例では、スーパーなるえつの担当者はサーバで、問い合わせをする側はクライアントと見立てることができます。

まずクライアントからサーバへ接続します。
ついでに「もしもーし」と相手へ挨拶してます。
@<fn>{no_request_on_the_protocol}

//footnote[no_request_on_the_protocol][電話問い合わせの場合、最初の「もしもし」が省略されるケースのほうが多いと思います。電話をかけてつながった時点で店は誰かから会話の要求があったことを理解出来るからでしょう。何かのメッセージを省略できるかどうかもコンピュータの場合はプロトコル（ルール）で決めておく必要があります。]

サーバからの最初の返答で、クライアントは少なくとも相手が「スーパーなるえつ」と名乗っていることを理解します。

次に客は「自分は名乗るつもりはない」と延べ、「大山の梅干し」の在庫に関する情報を求めるリクエストを送っています。
「認証」については後述しますが、ここでは「店は客が誰かを認識していない」という意味です。

「少々お待ちください」は特に人間同士で「そのレスポンスに対する回答には時間がかかる」ことを示すものです。
要求を処理する時間がかかった後、少なくともその要求に対してリソースがあることまではスーパーなるえつサーバは応答します。

残念ながらインターネットのようにクライアントは本物の梅干しを電話では直接受け取ることはできないので、
ここで電話のやりとりは終わりにして、実際に店舗に行った時に売り切れている恐怖と戦います。

=== プロトコルとは

コンピュータの分野では、プロトコルとは実際に異なる相手同士がやりとりをする約束事のことです。
Webサーバにしろ何にしろ、インターネット上でクライアントとサーバが通信するには、何らかのプロトコルが必要になります。

アプリ開発と同様、サーバとクライアントの両方を自分が作っている場合に限ってはプロトコルは自由に変更出来ます。
しかし一般には、相手は別の会社のサーバだったり政府のそれだったりするので、
ルールに基づいてアクセスしないと、無視されたり、あるいは悪者扱いされます。

=== 一つのプロトコルの上に動作するプロトコル

実際には「ネットワーク」の章でもTCP/IPなどのプロトコルを勉強しているかもしれません。
TCPもIPもPは"Protocol"です。
WebサーバはすでにTCP/IPというプロトコルを守ってるのではないでしょうか。

ではなるえつの例にちょっと戻ります。
なるえつと梅干しの例では最初、電話の受け取り側（サーバーです！）は電話の応答口が「スーパーなるえつ」であると言っています。
ここで、電話は通じていることが隠れた重要な前提です。

お店によっては、電話番号を公開してなかったり、支払いを忘れて電話が止められてたりします。
在庫確認はFAXでおねがいします、というスーパーもあるかもしれません。

さて、先ほどの例は、電話がつながることを前提としつつ、
電話がつながったからといって意思疎通ができるとは限らないことを示したものです。

なるえつに電話がつながった瞬間、相手が突然
「今朝、丸ノ内線で、すずらんの花が咲きました」と語りだしたら、客はマジで困ります。
歌を歌われたらもっと困ります。
客の我慢にも限度があります。

「電話がつながる」ことと「必要な情報を得られる」ことの間にはまだ隔たりがあるわけです。

「電話がつながる」ところまでが、言ってみればTCP/IPが保証している領域、
と考えるのが今はわかりやすいと思います。
最初に相手につながること、これ自体がまず何らかの取り決めの上になりたっています。
TCP/IPが担うのは、言ってみればそこです。

しかし「TCP/IP」といったプロトコルだけでは、Webサーバ上のデータをやりとりするのには不足です。
電話がつながっても、日本語である必要があるし、
日本語にしても適切な応対の幅があるというのもわかります（梅干しがなければ「ない」と答えます。）@<fn>{osi}

//footnote[osi][TCP/IPについて本当に前章で説明されているのか知らずに書いてますが、ついでに「OSI参照モデル」という言葉も紹介しておきます。なるえつの例で、ネットワークの授業の上で重要な点は「電話」と「その上でなされる会話」は別のレイヤ（層）に分けて考えることができる、ということです（在庫確認は電話でなくても出来ますね。）つきつめていくと、インターネット上でのやりとりは「7つの層」で説明できると考えるのがOSI参照モデルです。ぐぐるといっぱい出てきますので、このあたりの説明は、これで。]

=== コンピュータどうしのやりとりでは「プロトコル」はさらに大事

なるえつの例では、ある程度プロトコル（しきたり）みたいなものがある程度あるといっても、
相手の応答がおかしければ人間同士でなんとかする余地がありました。
相手がすずらんのことを話し始めたら
「焦るな。俺は大山の梅干しが食べたいだけなんだ。」
と返答すれば、もしかすると相手は正気に戻るかもしれません。

しかしコンピュータは、人間以上にアドリブに大変弱いです。空気を読めません。
@<fn>{chainber}

//footnote[chainber][コンピュータに「彼はなんと言っている！？」と聞いたときに丁寧に空気を読む回答をしてくるとすれば、そのコンピュータはチューリングテストにそのまま合格出来そうです。チューリングテストとはある機械が知的かどうか（人工知能であるかどうか）を判定するためのテストのことです（Wikipedia日本語版「チューリング・テスト」参照）]

コンピュータにおけるサーバとクライアントのやりとりでは、想定外の事態を含めていろいろな状況が起こりえます。
その状況を可能な限り網羅したプロトコル（つまりルール）を全て準備しておき、
クライアントとサーバの両方がそのプロトコルにしたがってデータを要求してデータを受け取る必要があります。
@<fn>{p2p_is_harder}

//footnote[p2p_is_harder][P2Pは、一般的にはサーバ・クライアントモデルよりも面倒な状況がさらに増える傾向があります。例えばWebをP2P的にしようとすると、WebブラウザはWebサーバ「としても」振る舞う必要が出てきますし、逆もしかり。]

=== RFC

複数人が共有するプロトコルの場合、特定の誰かが適当に決めるのでは問題があります。
その人が悪意を持っていたりすると他の人の迷惑になりますし、その人が気づかない問題があるかもしれません。
インターネットやWebのように大量の異なるプレイヤーが絡む世界でこれは大変困るので、
みんなで議論してみんなでルール（プロトコル）を決め、みんなで一斉に守ります。

Webにまつわるプロトコルの仕様は大抵の場合、公開で議論され、その結果も自由に見ることが出来ます。
特に、後述するWebに関わる仕様書の多くはRFC（Request For Comments）と呼ばれる一連の仕様書により定義されています。
@<fn>{other_specs}

//footnote[other_specs][RFCが仕様書の全てであるかのような記述に見えるかもしれませんが、IT業界で使われる仕様が全てIETFとRFCの管理下にあるわけではありませんし、世界中で相互に仕様を共有して運用する方法は多数あります。すでに出てきた例であるISBNはIETFとは全く関係のない仕組み・仕様で動いています。なお共有される仕様の中には企業が独自に策定する、いわゆるプロプライエタリなものもあります。その場合、その企業の思惑に応じて仕様がねじ曲げられて、利用する他の人が迷惑を被ったりすることもあります。RFCは言ってみればもう少し「民主主義的」です。]

RFCは、IETF（Internet Engineering Task Force）と呼ばれる組織によって発行される、技術仕様等に関する文書全体を指します。
RFCと称されるドキュメントはたくさんあり、それぞれに連番がふられています。
「RFC」のあとに数字をつけ、例えば「RFC 7230」といった形で
特定のRFCを参照します。@<fn>{many_rfc}

なお参考まで、RFCを管理するIETFは、特にインターネットで利用される標準について議論を行う組織です。
議論する対象に応じてワーキンググループを作成し、
メーリングリストでの議論の後、RFCを発行するなどして
そのワーキンググループの活動を一旦終了します。
なお、Webが活用するTCP/IPに関わる仕様もIETF由来です。

//footnote[many_rfc][現時点でも7000を越えるRFC文書があるのは事実ですが、全部がインターネットで活用されている、というわけではありません。特にエイプリルフールに発行されるRFCの中には完全にジョークのものがあります。1998年に公開されたRFC 2324の"Hyper Text Coffee Pot Control Protocol (HTCPCP/1.0)"などはわかりやすい一例で、私も学生時代に衝撃を受けた記憶があります。同RFCの"there is a strong, dark, rich requirement for a protocol designed @<b>{espressoly} for the brewing of coffee"（強調引用者）という表現から誰しもがコーヒーの芳醇な香りを想起しつつ、ええと、次へ。]

Request For Commentsは日本語に訳すと「コメント求む」なのですが、
実際には各RFCの文書は公開される前に多くの議論を経た上で公開され、公開後に大きな修正は行われません。
その点で、各ドキュメントは「コメント求む」という表現から想像するよりもはるかに成熟したものです。
RFC 何番と表現された場合、通常はお互いが差すドキュメントは完全に一致します。
仮に改善の必要があった場合には、誤りについてはerrataとして公開されますが、
不足や根本的な改善については次のRFCを議論し、過去のRFCを打ち消す形で次に活かします。

これから登場するWebに関わるプロトコルの多くはRFCに基づいた仕様が存在します。

ここまでで「サーバ」とそれに関わるプロトコルについての説明が終わりました。
「Webサーバ」とは要は「Web」におけるサーバで、そのためのプロトコルがあります。

では「Web」とは何でしょうか。

== Web

webという英単語は、もともと「蜘蛛の巣」を意味する英単語です。
この用語に絡めて、1990年にスイスのCERNという研究所に所属していたTim Berners-Lee博士がWorld Wide Webを提唱したのが、
現在のインターネット上のWebという言葉の始まりです。@<fn>{internet_existed_before_www}

もともと技術論文は、研究分野の他の論文を引用・参照しつつ研究を発展させます。
Web以前からあるコンピュータ上のドキュメントでも、ひとつのドキュメントと
他のドキュメントを相互参照する仕組みは備えていました。
同様に、インターネット上の文章にも同様の構造を作ることが出来るのではないか
という着眼点から、世界全体を一つの蜘蛛の巣と見立てるWorld Wide Webの発想を
提案書の形で公開したのがTim博士です@<fn>{www_proposal}。
一つ一つのハイパーリンクという他のドキュメントへの参照が蜘蛛の糸となります。
この後、1993年にイリノイ大学NCSA（Natiotal Center for Supercomputing Application）
がWebブラウザ"Mosaic"を公開し、大ヒットとなります。
以後、Webの利用は爆発的に普及し、今に至ります。

//footnote[internet_existed_before_www][情報共有を行う手段自体は1990年以前から存在しました。例えばWikipediaの「電子メール」の記事によれば1965年に世界最初の電子メールが使われ始めた、とあります。]
//footnote[www_proposal][最初の提案をW3C（The World Wide Web Consotium）のWebサイト@<href>{http://www.w3.org/Proposal.html}で読むことが出来ます。ブログやTwitterどころかWebページという概念が一般に存在しない時代のことです。なお、本文の説明や他著で、まるでTim博士が一人でWorld Wide Webを発明したかのような説明になりがちなのですが、実際にはいろいろな主体が影響を与え合う中で提案書が書かれたのでしょう。本章執筆担当者が眺めた日本語書籍の中では『Webを支える技術』がおそらく細かな時代背景をよく説明していると思いました。もっと細かくWebの歴史を知りたければそういった書籍をあたってみる方がよいでしょう。]

Webでは当初から、相互にリンクのある「ハイパーテキスト」をWebサーバに配置し、それを人がWebブラウザで見るという用途が想定されています。
これを達成するため、まず3つの主要が重要であると言われます。

 * HTML（Hyper Text Markup Language）は、「ハイパーテキスト」を記述するためのマークアップ言語@<fn>{markup_language}です。
 * URI（Univarsal Resource Indicator）は、世の中のモノ（リソース）を一意に指し示すための文字列の仕様です。
 * HTTP（Hyper Text Transfer Protocol）はHTMLをWebブラウザが要求してWebサーバが返答するやりとり自体に用いるプロトコルです。

//footnote[markup_language][マークアップ言語は「文章の構造（段落など）や見栄え（フォントサイズなど）に関する指定を文章とともにテキストファイルに記述するための言語」です。（Wikipedia日本語記事より）有名なものとしてHTMLがあります！]

この中で、本章を読んでいる人はさすがにWebページを全く見たことがないという人はいないでしょうし、
HTMLがWebページを記述する一種のプログラミング言語のようなものだということも誰もが知っていることと思います。

そこで本章ではURIとHTTPについて紙面を割くことにします。

=== URI

Webページを開いたことがあれば、一意の識別子があることも知っているかと思います。
例えば@<href>{http://techbooster.org/}と書けば、後述するHTTPというプロトコルで動作するTech BoosterのWebサイトのトップページ
を示す一意の表現を得ることが出来ます。@<fn>{homepage}

//footnote[homepage][「ホームページ」という表現は本来特定のWebページの最初のページという意味でしたが「Webページ」と同様に使われていました。そう言えば「ホームページ」という表現、最近はあまり聞かなくなりましたね。]

HTMLとの連想ではURL（Universal Resource Locator）という表現の方を多く見たかもしれません。
ただし、現在、WebサーバーやHTTPの仕様上で使われるのはURIの方です。

==== URI, URL, URNの違い

歴史的にはURLという概念が先に登場しました。
前述したWorld Wide Webの時点で他のWebページへのハイパーリンクを作成する際に、相手のWeb上の「場所」を特定できる必要があったためです。

しかしその後、リソースを特定する上では「場所」だけでなくその「名前」自体を
一意に特定できるべきだ、という議論が主流となり、
「場所」を示すURLという概念に加えて「名前」を示すURN（Universal Resource Name）も
一般的に認知されるようになりました。

URLとURNは人間で言う氏名と住所の違いに近いと言われます。
他にもURなんとかというのは提案されたそうですが、現在では下火です。

例えば、本のISBN番号を表現するために"urn:isbn:4844335340"というURNを用いることができます。
このURNによって、某社の某書籍の存在を曖昧さなしに表現できます。@<fn>{effective_android}

//footnote[effective_android][種明かしをすると『Effective Android』という技術書のISBN番号です]

ただし、URNではEffective Androidという技術書を一意に特定できても、
Web上のどこにその本の情報があるか、どこで購入できるか、といった場所についての情報は伴いません。
Web上の場所を指す場合には「場所」を一意に特定するURLを使用します。
urn:isbn:4844335340 をオンライン書店Amazonで購入する場合
@<href>{http://www.amazon.co.jp/dp/4844335340}へアクセスしてください、といった説明ができます。

URLとURNをまとめてURIと呼びます。
URI、URL、URNの関係については、RFC 3986に詳細な説明があります。

URNはWeb上の「場所」を示すことが出来る「URL」としての役割を果たすことはありません。
HTMLのhrefとして記述してもWebブラウザは多分どこにも移動してくれません。
URIということで<a href="urn:ietf:rfc:1458">RFC 1458</a>と書いてもこのリンクはWebブラウザ上では意味がないでしょう。

RFC 3986の記述を参照する限り、今後のWebに関する議論では、URLに相当する情報を強調する目的がない限りは
全てURIで統一するのが適切ですが、今でもURLという表現がWebサーバやその周辺実装の説明では自然に登場しますので、
読者はどちらが登場しても驚かないようにしておきましょう。

====[column] まだURNのことがわからない場合のもう一例

RFCという言葉について考えてみましょう。
ここまでの説明を読むと「RFC1458」という文字列からはRequest For Commentsの1458番という技術文書のことだと予想したくなります。

しかし実はラジオ福島のことかもしれません。周波数として1458kHzを使っていて、かつ短縮名がRFCなんですね。
@<fn>{radio_fukushima}

//footnote[radio_fukushima][@<href>{http://www.ustream.tv/user/rfc1458}というURIは存在し、どうやらこれはラジオ福島のユーザアカウント情報を表示するWebページのURIです。]

要は「RFC1458」という表現では、世の中の人が同じものを想像をして議論するには不十分です。
一方がその番号の技術文書の内容がダメだという意味で「RFC1458マジダメくさい」とTwitterで書くと、
ラジオ福島の人がそれを見てしょんぼりしてしまうのです(´・ω・｀)

一方urn:ietf:rfc:1458であればRequest For Commentsの1458番であると間違いなく判定できます。

====[column]  JavaのURLクラスとURIクラス

JavaにはURLとURI、両方のクラスがあります。
ここで本章担当者としては紹介せずにいられないJava Puzzleがあります。

http://youtu.be/wDN_EYUvUq0?t=9m50s

相当古い動画なのですが、仕様上今でも問題になるURLクラスとURIクラスのSet内挙動が異なる点を
指摘した例として、当時新入社員だった筆者としても大変驚いた記憶があります。

調べたところ、URLクラスはJDK1.0、URIクラスは1.4の導入とのことです。

どちらかというと初期のJavaのライブラリ設計の失敗に関わるものですが、
「古い」というのはしばしばそういう問題も引き起こす、ということで一つ。

=== HTTP

ネットワークの章でTCP/IPの上で複数の異なるプロトコルのパケットが行き来していることを学んだかと思います。
Webサーバの場合にTCP/IPの上で使われるのは、HTTP（Hypertext Transfer Protocol）というプロトコルです。

Webサーバとやりとりする基本的なプロトコルであるHTTPでは、
クライアントからサーバへ要求（リクエスト、request）を送り、
サーバがそれに対する応答（レスポンス、response）を返します。

HTTPはWebの屋台骨となるもので、理解するのは結構大変です。
まず実際にHTTPで通信される中身を見てからプロトコルの中身を勉強することにします。

==== 演習: telnetでHTTPのリクエストとレスポンスを見てみよう

さてここでHTTPの詳細に踏み込む前に、実際にHTTPのリクエストとレスポンスを体験してみることにします。

ここで登場するのがtelnetというプログラムです。
HTTPのみならずTCP/IP上で動作する各種のプロトコルの検証に使われることがあります。
@<fn>{telnet_has_rfc}

//footnote[telnet_has_rfc][Telnetというのはもともと上述したRFCの中でもRFC 854で規定された立派なサービスの名前ですが、現在telnetと呼ぶ場合、しばしばこれから使う「便利なプログラム」という意味になりがちです]

@<list>{telnet_example}にTech InstituteのWebページヘアクセスした例を示します。
@<fn>{other_web_page}

//footnote[other_web_page][別のWebサイトでも試せますが、まずWebブラウザでそのWebページを表示できること、さらにそのURIがhttpsではなくhttpであること（URIの冒頭のhttpのあとに「s」がついてないこと）を確認してからの方がよいでしょう。この理由については後述します。]

//list[telnet_example][telnetコマンドの実行例]{
$ telnet techinstitute.jp 80[Enter]   <----------- "telnet" 以降を入力してエンターを押してください。
Trying XXX.XXX.XXX.XXX...    <-------------- 実際には正規化されたIPアドレスが表示されます
Connected to techinstitute.jp.
Escape character is '^]'.
GET / HTTP/1.1[Enter]   <-------- "GET / HTTP/1.1"と入力してエンターを押してください
Host: techinstitute.jp[Enter]   <------ 上と同様エンターを押します
Session: close[Enter]  <----- 上と同様
[Enter]           <----- 最後に何も入力せずに再度エンターを押します
HTTP/1.1 200 OK
Date: Sun, 06 Jul 2014 06:19:43 GMT
Server: Apache/2.2.23 (Unix) mod_ssl/2.2.23 OpenSSL/1.0.1h
X-Powered-By: PHP/5.5.9
Connection: close
Transfer-Encoding: chunked
Content-Type: text/html

13e
<!doctype html>
<html>
<head>
<meta charset="UTF-8">

..(HTMLぷしゃー)

</html>

0

Connection closed by foreign host.
$   <-------- telnetコマンドが終了します
//}

空行でエンターを押した後は、Webサーバが実際にHTTPのレスポンスをtelnetのアプリケーションに返答します。
@<fn>{maybe_bad}

//footnote[maybe_bad][本当は許可を得て使うところです。後述するウェブ・スクレイピング同様、あまりやらかすと本当に怒られるので、本稿を書いている担当者は実はちょっとビビりながら書いています。]

実際に入力した内容を追いかけながら、HTTPのリクエストとレスポンスについて順番に状況を追ってみましょう。

//list[telnet_example_part1][telnetコマンドの実行例（１）]{
$ telnet techinstitute.jp 80[Enter]   <----------- "telnet" 以降を入力してエンターを押してください。
Trying XXX.XXX.XXX.XXX...    <-------------- 実際には正規化されたIPアドレスが表示されます
Connected to techinstitute.jp.
Escape character is '^]'.
//}

@<list>{telnet_example_part1}ではターミナルからtelnetコマンドを実行し、techinstitute.jpの80番ポート（HTTP）へアクセスを指定しています。
これによって、telnetがWebサーバへTCP/IP接続を開始します。

それ以降の3行はtelnetコマンドがコマンドを実行したユーザへわかりやすく文字列を表示しているもので、HTTPとは関係がありません。@<fn>{about_telnet_messages}

//footnote[about_telnet_messages][背後でTCP/IPを介してXXX.XXX.XXX.XXXというIPアドレスのサーバ（の80番ポート）へ接続し、接続が成功したことを伝えています。最後の"Escape character is '^['"は接続をクライアント側から終了する際に、ユーザがCtrl+\]を入力すれば良いことをtelnetコマンド自身が伝えています。]

//list[telnet_example_part2][telnetコマンドの実行例（2）]{
GET / HTTP/1.1[Enter]   <-------- "GET / HTTP/1.1"と入力してエンターを押してください
Host: techinstitute.jp[Enter]   <------ 上と同様エンターを押します
Connection: close[Enter]  <----- 上と同様
[Enter]           <----- 最後に何も入力せずに再度エンターを押します
//}

@<list>{telnet_example_part2}ではユーザは実際にHTTPのリクエスト、具体的には「GETリクエスト」を送っています。
説明を端折ったものを@<list>{telnet_example_part3}に示しましょう。

//list[telnet_example_part3][telnetコマンドの実行例（3）]{
GET / HTTP/1.1
Host: techinstitute.jp
Connection: close

//}

最初の行はリクエスト行（Request Line）と呼ばれています。
その次の行から空行までの「〜: 〜〜」で記述された2行は「ヘッダフィールド（Header Fields）」と呼ばれます。

改行コードについて、現在コンピュータ上ではCR、LF、CRLFの3種類がしばしば混在して使われていますが、HTTP 1.1では改行は「CRLF」と決まっています。
@<fn>{telnet_may_not_use_crlf}

//footnote[telnet_may_not_use_crlf][telnetコマンドは実は標準ではCRを改行コードとして送ります。つまり、今回の例だけですと、厳密にはプロトコル違反の改行コードで通信が成立している点は指摘しておきます。大変よくあるプロトコル違反である関係でサーバ側も許容していることが多いのですが、複雑なケースではWebサーバの脆弱性の元になる大変危ういことを実はやっています。ちなみにtelnetから送信する改行コードを変更する方法は、telnetのマニュアルを見ましょう]

3行からなるGETリクエストの冒頭で、実際に取得したいコンテンツとHTTPのバージョンを指定しています。
実は半角空白で区切られた真ん中の"/"がコンテンツの場所を意味しています。
今回の場合この最初の行は"GET http://techinstitute.jp/ HTTP/1.1"と同じ意味です。
ヘッダに含まれている"Host"行と"Connection"行については一旦おいておきます。

//list[telnet_example_part4][telnetコマンドの実行例（4）]{
HTTP/1.1 200 OK
Date: Sun, 06 Jul 2014 06:19:43 GMT
Server: Apache/2.2.23 (Unix) mod_ssl/2.2.23 OpenSSL/1.0.1h
X-Powered-By: PHP/5.5.9
Connection: close
Transfer-Encoding: chunked
Content-Type: text/html

13e
<!doctype html>
<html>

... （HTML）

</html>

0

Connection closed by foreign host.
//}

この部分は全てWebサーバから送られてくる「レスポンス」です。
一行目（"HTTP/1.1 200 OK"）はステータス行（Status Line）と呼ばれ、
実際にWebサーバが返答するHTTPのバージョンと、リクエストがどう処理されたかの「レスポンスコード」
が記述されます。
それ以降、空行まではやはり「ヘッダ」です。
ここにサーバの情報や返答してきたデータの種類などが記述されています。
具体的には「Apacheと呼ばれるアプリケーションでホストされていること」
（"Server: Apache/2.2.23 ..."）や
「プログラミングPHPを用いて実装されたサービスであること」
（"X-Powered-By: PHP/5.5.9"）、
「返答したデータがHTMLであること」（"Content-Type: text/html"）
などが記載されています。

そのあと、空行（CRLF）を挟んで、実際のデータです。メッセージボディと呼ばれます。

なお今回の例では、Webサーバへ送ったリクエストの方には、改行の後のメッセージボディを何も入力していません。
これは単にメッセージボディが今回のリクエストでは空であっただけで、場合に寄っては送ることもあります。
例えばWebページでよくある問い合わせフォーム等では実際にボディにデータが入ることがあります。
なので、「最初の1行」「ヘッダ」と「ボディ」という構造は、HTTPのリクエストとレスポンスの両方で共通しています。
@<fn>{chunked}

//footnote[chunked][レスポンスのメッセージボディですが、HTMLの前にこっそり"13e"とあり、さらに末尾に0という数字もついています。つまりHTMLを返すよ、と言っていながらも、Webサーバが実際に返すメッセージボディにはHTML以外の「ゴミ」が混じっています。これはレスポンスヘッダにある"Transfer-Encoding: chunked"の指定があるためです。一般的なHTTP関連の教科書や入門的な説明では、直接HTMLデータだけメッセージボディに入るのですが、今回試したWebサイトがこういうリアルな返答を返したので、ややこしいですがそのまま表記します。HTTPレスポンスについての説明のところでもう少し説明します。]

telnetでHTTPを実際に「しゃべって」みました。
ここからHTTPのリクエストとレスポンスの基本的な構造についてもう少し説明していきます。

#@warn(TODO: Windows8でのtelnetの使い方を書く)
#@# ====[column] Windows8でのtelnetの使い方

==== HTTPのリクエスト

telnetの例でのリクエストをもう一度見て未ましょう。

//list[telnet_example_part3_2][telnetコマンドの実行例（3）再掲]{
GET / HTTP/1.1
Host: techinstitute.jp
Connection: close

//}

TCP/IPでWebサーバへの接続が完了後、
クライアント（Webブラウザ等）は最初の行（リクエスト行、Request Line）で、リクエストの種類（リクエストメソッド、Request Method）、
リクエストの対象、そして自分が利用しているHTTPのバージョンの3つの情報を指定します。

リクエストメソッドについて、HTTPにはたくさんの種類がありますが、
ここで学ぶのは「GET」リクエストと「POST」リクエストです。
両方共クライアント、つまりWebクライアントの側から送るリクエストの種類です。
その他にはPUT・HEAD・DELETE・OPTIONSなどいくつかありますが、ここでは説明を省略します。
一部後の節で登場します。

ここではGETメソッドの対象として"/"、つまりルートディレクトリのデータを要求しています。
HTTPのバージョンは1.1を期待しています。
大方のWebサーバは要求通りHTTP/1.1でレスポンスを返してくれますが、必須ではありません。

2行目から空行まではヘッダで、必要なフィールドとして"Host"が定義されています。
HTTP/1.1ではこのヘッダ情報は必須です。

"Connection"行は必須ではありませんが、今回はサーバ側の応答の関連でつけています。
今回の例でこれを付けずにGETリクエストを送ることも出来ます。その場合、telnet

===== GET・POST・その他

GETリクエストはサーバからデータ（もしくはリソース）をダウンロード・取得したいというときに使います。
telnetでの例で使ったメソッドでもあります。
GETリクエストではメッセージボディに相当するものは空であることが一般的です。

POSTリクエストはサーバへデータを送る際に用います。
GETの例では空だったHTTPのリクエスト側のメッセージボディに具体的に値をつめこみます。
メッセージヘッダに"Content-Length: 3000"のようにボディの長さを入れておきます。
このときも、WebサーバからはレスポンスとしてHTMLなどを普通に返送するので、
GETリクエストとPOSTリクエストは画面だけ見るとあまり差に気づきません。

特定のWebページをリロードする際にブラウザが「フォームを再送信しようとしています」と
警告を表示することがあります。これはPOSTリクエストの結果として表示されたページを送信するときに表示されます。

#@warn(TODO: フォームのリロード時の警告のスクショを貼る)

WebサーバがPOSTに関わるデータを重複して送ると、しばしばおかしな結果になります。
インターネット掲示板で同じ投稿を二度受け付けてしまったり、銀行のWebサービスで振込を二度受け付けてしまったりするのです。
サーバ側で対処する方法もあるのですが、POSTなら2度は再送するメリットは普通あまりないため、
ブラウザでも警告を出すわけです。

なお、GETでは警告は出ませんが、URIで説明したクエリ文字列の仕組みを用いると、
実は少量のデータであれば送れます。こちらではWebブラウザからの警告はないので、
GETのクエリ文字列でWebサーバに保存するデータが変わる場合、
このWebページをリロードするのはまずいことがあります。

仕様で強制されているわけではないのですが、
Webサーバの実装のスタイルとしてはGETは「read-only」（読み取り専用）的に動作させるのが一般的です。
クエリ文字列は「検索方法を変える」といった指定にのみ使うべき、と言えると思います。
@<fn>{cachable}

//footnote[cachable][Webにおいてはレスポンスの高速化のためにキャッシュサーバを使うことがあります。HTTPではキャッシュしても良いリクエストについて色々と説明・規定があります。GETリクエストのレスポンスが読み取り専用だとすれば、キャッシュの最有力候補です。ここで、コンテンツに書き込みを行うことをWebサーバが求められていたりすると、キャッシュ出来ません。]

なお、ここではGETとPOSTしか説明しませんが、PUTやDELETEというメソッドもHTTPというプロトコルには存在し、
Webサーバにそのリクエストを行うことが一応出来ます。
ただ、Webブラウザの範囲ではほぼ使うことはありません。
後述するRESTやJavaScriptの文脈で他のメソッドが使われることがあります。
@<fn>{naruetsu_again}

//footnote[naruetsu_again][なるえつの梅干し問い合わせの例をHTTPのメソッドに強引に当てはめると、GETではなくHEADというメソッドに相当します。HEADメソッドをクライアントから送られた場合、Webサーバはリソースがあるかないか、といった情報を返しますが、リソースの中身は返しません。]


==== HTTPのレスポンス

HTTPレスポンスは、リクエストに対する応答です。
telnetの例で現れた例をもう一度見てみましょう。

//list[telnet_example_part4_2][telnetコマンドの実行例（4）再掲]{
HTTP/1.1 200 OK
Date: Sun, 06 Jul 2014 06:19:43 GMT
Server: Apache/2.2.23 (Unix) mod_ssl/2.2.23 OpenSSL/1.0.1h
X-Powered-By: PHP/5.5.9
Connection: close
Transfer-Encoding: chunked
Content-Type: text/html

13e
<!doctype html>
<html>

... （以下HTML）
//}

最初の行でHTTP/1.1とあるのは、サーバが実際にHTTPのバージョン1.1で返答した、という意味です。
リクエストの冒頭の行でHTTP/1.1と書いてあれば大抵ここも同じバージョンを返しますが、
まれに異なる返答がありえます。
HTTP 1.1はHTTP 1.0に対する後方互換性維持が仕様上想定されており、古い1.0が返答されても仕様違反と怒ることは出来ません。
@<fn>{can_contact_using_09}

//footnote[can_contact_using_09][一部の大手サーバでは現在でもHTTP/0.9風のレスポンスを返してくれることがあります。本稿執筆時に間違って"GET /"と書いたらヘッダなし（0.9なので）でHTMLが返ってきて変に感心しました。]

第一行目のステータス行（Status Line）にはHTTPのバージョンのあと、そのリクエストの簡潔な結果をかえす3桁の数字「ステータスコード」（Status Code）が返され、
その後の3桁の数字の説明書きが続きます。
説明書きは数字の定義をそのまま説明したもので、無視できます。

ステータスコードは左端の桁が主要な理由を示しており、残りの2桁でより具体的になります。
ここでは代表的なものをいくつか挙げるにとどめましょう。

 * 200 OK: リクエストで要求されたものが存在したので送りますよ、
 * 301 Moved Permanently: リクエストしたリソースは永久に別の場所へ移動しました。
 * 404 Not Found: そんなリソースは知りません
 * 508 Internal Server Error: サーバ内部でエラーが発生しちゃった！

今回は"200 OK"とあります。そして実際、そのリソースに対応するHTMLが返送されています。
該当するWebページが別のURIで示された場所に移動した場合、代わりに301が返答されることになります。
クライアントが指定したURIに誤りがあったりした場合、サーバは単に「そんなの、ない」と言います。
もしサーバがそのタイミングでエラーを出した場合（例えばJavaでサーバを書いてたとするとNullPointerExceptionでクラッシュしちゃった場合などですね）、
Webサーバは508で「ごめんなさい」します。
ちなみにHTTPレスポンスコードの200番代は「正常」、300番代は「移転」、
400番代は「クライアント側に問題がある」、500番代は「サーバ側に問題がある」という大まかな区別があります。@<fn>{teapot}

//footnote[teapot][RFC 2324によればHTTPのレスポンスコード418 I'm a teapotはティーポットでコーヒーを入れようとしたときに抽出するエラーです。クライアントが容器を間違えているのでありまして、紛うことなき400番代の引き締まった香りがいたします]

HTTPではヘッダに"Content-Type"というフィールドを入れることで、メッセージボディの中身がどのような種類のデータかを指定できます。
HTMLを返す場合には"text/html"といった文字列が入りますが、ただのプレーンテキストの場合は"text/plain"と指定すれば、多くのWebブラウザがそれを適切に処理します。
最近ではPDF（Portable Document Format）も一般的で、メッセージボディにPDFを入れることももちろん出来ます。
その場合は"application/pdf"を指定します。@<fn>{mime_type}

//footnote[mime_type][この"text/html"等の記載をMIMEタイプと呼び、RFC 2046で規定されています。そこで実際に記載されうる文字列の標準はIANAという組織が管理しています。「多くのブラウザ」が適切に処理できるのは仕様と標準が定まっているからです。]


Content-Type と呼ばれる情報と、実際のデータ（Content）を返します。
Contentは「中身」です。@<fn>{contents}

//footnote[contents][ちなみに日本語でも「コンテンツ」という表現で使われますが、これはWebページの中身やエンターテイメントのような商品のニュアンスがありますね。ここではあくまで送られてくるデータの中身のことです。]

非常に典型的なのは「このWebページですね。どうぞ」と
「そんなWebページ、ない」という2種類の応答です。



本章では立ち入りませんが、レスポンスコードはプロトコルで規定されていつつも、
歴史上の理由でしばしば仕様通りに返答を返してくれないWebサーバもあります。
ここでは「仕様無視！そういうのもあるのか」という程度で軽く理解しておくことにしましょう。

#@warn(TODO: 実際にリクエストの中身とレスポンスの中身を平文で書く。telnetの結果みたいなもの)


==== 演習: Android アプリからWebサーバにアクセスしてみよう

さて、ここでは実際にAndroid経由でHTTPアクセスをしてみましょう。
ここでは@<code>{java.net.HttpURLConnection}を用いることにします。

#@warn(ネットワークの章でWebサーバへアクセスする事例は終了している可能性が高い。要調整)

====[column] DefaultHttpClientとAndroidHttpClient について

HTTPアクセスを行うライブラリは他にも@<code>{org.apache.http.impl.client.DefaultHttpClient}や
@<code>{android.net.http.AndroidHttpClient}といったライブラリが紹介されることがあります。
しかし本稿ではそれらの理由はおすすめしません。
現時点でこれらの実装にはバグが多く、今後もメンテナンスされる見込みがないと考えられているためです。
なお、非常に古いAndroidのバージョン（2.2）では@<code>{java.net.HttpURLConnection}にバグがあったため、
それらの古いバージョンでは注意が必要です。

 * 参考: Android Apache HTTP Client と HttpURLConnection どっちを使うべき？ @<href>{http://y-anz-m.blogspot.jp/2011/10/androidapache-http-client.html}@<fn>{this_is_also_old_article}

//footnote[this_is_also_old_article][記事の公開2011年10月4日に公開された点も出来れば]

==== Cookie

HTTPはもともと「ステートレスなプロトコル」と言われます。
HTTPの仕様の中には「前回の状態をサーバやクライアントは覚えておいてね♪」と要求している項目がないという意味です。

ここでハンバーガ屋と得意客の例を考えてみます。

#@warn(TODO: このハンバーガ屋の例はステートの意味を取り違えている。変える)

ハンバーガ屋に行き「ツケといてくれ、旦那」と客が支払いを後回しにもできるのがステートフルです。
「ステートフル」は英語でStatefulで、「状態を保持している」という意味です。
ハンバーガ屋は客のツケの金額等を覚えておく必要があります。

ステートフルな場合、次に行った時「この前のツケ、払ってくださいよ」と言うことができるように、
ツケという状態をハンバーガ屋が覚えておけるのが、ステートフルの一見したところ良い点です。
しかし、江戸時代からある下町のハンバーガ屋がお得意客数名に対してこれを行えても、最近の全国チェーンでこれは無理と言えます。
ステートを保持するのはコストがかかります。

というよりも全国チェーンでは「40分後に取りに来ますのでその時に出して」というステートだって、割と断られます。
非常にたくさんのお客を相手にうまくサービスを行き渡らせるには、客は逃げ出さない前提でその場で払ってその場でものをもらうのが通例です。
つまり、自動販売機のように前のことを何も覚えていないのがステートレスです。@<fn>{stateful_burger}

//footnote[stateful_burger][ちなみにこの無理矢理な例で言うと、番号札を渡して店員が後から席に持っていくモデルは、十分ステートフルなサーバです。しかし秒間1万リクエストくらい来る先進的なハンバーガ屋だとこれすら無理です。ステートレス・バーガーが素晴らしいわけです]

しかし実際にWebサーバを介してアクセスすると、
多くのWebサービスでは、ユーザ名とパスワードなど、いろいろなものをWebサーバが記憶しているように見えます。
特に、ブラウザを閉じてもそれらが残っているのは驚きです。

この大方の欲求に対処するのがCookieと呼ばれる仕組みです。
RFC 6265が参照できる仕様ですが、歴史的事情で完全にこのRFCの通りには動作しないとのことです。
@<fn>{rfc6265}

//footnote[rfc6265][Webではしばしばこういう話があります。次の章でもっと生々しい話をご紹介します。]


== プログラミングインターフェースとしてのWeb

これまで説明してきたとおり、Webは当初、
人がコンピュータにアクセスして「ハイパーテキスト」を閲覧するものでした。

しかし現在のWebはそれだけにとどまりません。
Webサーバを介して人を介さずにコンピュータやアプリ同士が通信を行い、
データをやりとりしている世界もまたWebです。

本説ではHTTPやURIという中心的な仕組みはそのままに、
コンピュータ同士が通信する場としてのWebを考えていきます。
当然、この「コンピュータ」には読者が作るであろうAndroidアプリも含まれます。

=== XML、JSON

すでに説明したとおり、HTMLは人が読む「ハイパーテキスト」を記述した言語です。
つまり、そこには人が読める文章があり、リンクがあります。
見栄えを整えるため、CSSのように文章全体、Webページ全体を装飾する必要もあります。

しかしコンピュータ同士であれば、通信する内容は単純な「データ」であるほうが便利です。
CSSのような装飾はむしろ邪魔です。

天気予報の情報をWeb上で収集する例を考えます。
人間が天気予報を見る場合、特定の日付・時間帯の天気、気温、湿度が
図表で表示されているのが理想的です。
もしある特定の地方を見たいのであれば、
地図の上にそれらの情報が載っているのがより使いやすい「天気予報」
になるでしょう。

#@warn(ここに天気予報アプリか天気予報のWebページの画像)

では、アプリがその情報を自動的に取得する場合はどうでしょうか。
アプリ内で画像から欲しいデータを抽出するのは比較的高度で面倒な処理です。
一方、次のようなデータであれば、比較的対処はしやすいでしょう。

#@warn(JSONもしくはXMLの天気予報データ)

人間がWebブラウザを経由してWebサーバから情報を取得する場合、多くの場合はHTMLが返されます。
しかしAndroidアプリが情報を取得する場合、
人が見るために整形されたHTMLを取得するのは冗長です。
別のフォーマットの方がより適しています。

HTTPでは、WebサーバがContent-Type と呼ばれる情報を返してクライアントに返答するデータの種類を返答することはすでに説明しました。
ここで、人が読めるHTMLではなく、XMLやJSONを返答することをWebサーバは選択できるのです。

この場合、HTTP（@<b>{Hyper Text} Transfer Protocol）はもはやハイパーテキストを送るという当初の役割を超えて利用されることになります。
すでにWeb

===[column] ウェブスクレイピング

XMLやJSONのようにアプリで簡単に処理出来る形式でデータを提供してくれない場合があります。
人が読むWebページ（HTML）からパターンを抽出して欲しい情報を取り出すことを「ウェブスクレイピング」と呼び、現在でも行われることがあります。
Googleが検索結果をWeb上から収集するのには必須の方法です。

アプリを開発する上でもしばしば便利と感じることがあるでしょう。
例えば、人気テーマパークの混雑状況を調べることを考えます。@<fn>{warned}

//footnote[warned][すぐに後述する通り、この方法には技術以外の問題があります。逮捕されることもありますので、最後まで読んでから考えましょう。]

来場者や来場を計画している人が見るためのHTMLで書かれたWebサイトはあっても、
XMLやJSONによるデータフォーマットを提供していないことがあります。
そこで、来場者が見るためのWebサイトのHTMLを解析して機械的に解釈できるデータに変換します。
特定のタグの中にある「混雑状況: スッカスカ！」の「スッカスカ！」の部分から
「混雑度が20%未満の場合こう表示されるのだな」と推測するなどして、
アプリのデータとして利用するのです。
ここが「混雑状況: 激混み！」に変わったら、アプリは自動的にそれを検出し、
Androidの通知フレームワークを介してユーザにそれを教えられるわけです。
便利そうですね。

しかし、基本的な考え方の単純さとは裏腹にこの方法は色々と問題を起こすことがあります。

一つ目の問題はWebサーバへの負荷です。XMLやJSONと異なり、この方法でアプリがWebページを読み込む場合、Webサーバは人間が本来読むデータ全体を返します。このとき、Webサーバの前提は「人が読むので一人あたりではそんなに高頻度では来ないだろう」という見込みがあります。

しかしアプリの場合、このアクセスを5秒おきに行うことすら可能です。
要は「F5アタック」をアプリが行い続けるようなものです。
Webサーバからすると、行い方次第では大変迷惑な行為になります。

2つ目の問題は、そもそもそんな用途としてデータを公開することを想定していない、ということです。
XMLやJSONを提供している場合、少なくともアプリから読まれるという意図を持って行っています。
その場合ですら、利用規約等によっては利用方法は限定されます。
HTMLのみで提供される、特に今回の例のような情報は、アプリで自動収集されることを特に望まれてないデータと予想できます。
かりに来場者全員が上の情報を元に計画を立てたとします。
すると「大変合理的な」ユーザの群れが「スッカスカ！」に大挙するなど、
本来のユーザの動きとは大きく異なる状態になるのは明らかです。

もともと、来場者の利便性を向上させるためであることは明らかですが、
運営者は意図を超えての情報利用は嫌がります。
おそらくそのサービスの利用規約にも似たような文面があるに違いないのです。

#@warn(TODO: どこかのサービス規約を読む)

一つ目も問題なのですが、2つ目の問題で世間の常識と技術の常識が乖離していたことから逮捕騒動に至った事例があります。
（「岡崎市中央図書館事件」もしくは「Librahack事件」）
この事例ではサーバ負荷を低減させるためのスケジューラを実装し、技術的にはどう考えても高負荷とは言えない方法でアクセスしたところ、
Webサーバ側に問題があるにも関わらず一方的に逮捕されたという事案です。
本事件は本章筆者が解説出来るレベルを超えているためこれ以上の説明や解釈は行いませんが、
少なくともそういう事件があったことは、アプリ開発者は覚えておくと良いでしょう。


=== 実習: 天気の情報を取ってくる

== PKI
== SSL接続
=== UrlHttps を試す

== 認証・認可

 * 認証: 本人確認
 * 認可: アクセス許可

コンピュータの世界から離れて役所で公的な証明書を受け取ることを考えてみます。
例えば、戸籍。

申請書類を書いて、免許証と申請書類を提出し、
役所が大丈夫だと思えば、役所が持っている情報を提供してくれます。

免許証を見せることは自分が本人であることの確認です。
もし「自分である」ことがわかれば、方法は複数あります。

しかし、見せたからと言って、申請する書類の許可が常に得られるとは限りません。
あなたが誰であるか、とその人に何かを行う許可を与えることは別のことです。


== その他のサーバ

本章を始めとする一連の説明は、Webサーバについての説明を中心としています。
しかしインターネット・クラウド上にあるサーバはそれだけにとどまりません。

 * メールサーバ
 * ファイルサーバ
 * プリントサーバ

「プリントサーバ」について補足しましょう。

Word文書を印刷したりするために、プリンタを利用することは多いと思います。
昔のプリンタはUSB接続やその他の接続でPC1台とつながりませんでした。
しかし業務用プリンタや最近のプリンタは賢く、
複数台のパソコンやAndroid端末などから「このデータを印刷して」という要求を受けて、印刷を行います。
リクエストを受けて、レスポンスとして印刷するので、これもサーバです。

Webサーバと通信するためにプロトコルとして「HTTP」が重要でした。
同様に、各サーバではその用途に応じてプロトコルが必要です。

 * メールサーバ ... POP, IMAP, SMTPなど
 * プリントサーバ ... IPP, LPRなど
 * ファイルサーバ ... SMBなど

全てではありませんが、これらのプロトコルの多くも仕様、特にRFCで規定されたりします。@<fn>{not_rfc}

//footnote[not_rfc][インターネット上で利用されるプロトコルの全ての仕様が完全に公開されるとは限りません。通信する相手同士が合意するためのルールがプロトコルですから、合意が秘密裏に行われていても動作すればその二者（二社）にとっては十分と言えます。その場合はそれを知らない人が参加できないので、「ケチ」とか「いじわる」とか言われますが、合意の難易度は場合によっては飛躍的に下がることもあります。この点については次章でもう少し考えます]

== まとめ

本章ではWebサーバと通信する上で必要な基礎知識について説明しました。
