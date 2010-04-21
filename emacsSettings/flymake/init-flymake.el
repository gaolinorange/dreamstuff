<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<!-- saved from url=(0046)http://www.emacswiki.org/emacs/init-flymake.el -->
<HTML xmlns="http://www.w3.org/1999/xhtml"><HEAD><META http-equiv="Content-Type" content="text/html; charset=UTF-8"><TITLE>EmacsWiki: init-flymake.el</TITLE><LINK rel="alternate" type="application/wiki" title="編輯本頁" href="http://www.emacswiki.org/emacs?action=edit;id=init-flymake.el"><LINK type="text/css" rel="stylesheet" href="./init-flymake_files/wiki.css"><META name="robots" content="INDEX,FOLLOW"><LINK rel="alternate" type="application/rss+xml" title="EmacsWiki" href="http://www.emacswiki.org/emacs?action=rss"><LINK rel="alternate" type="application/rss+xml" title="EmacsWiki: init-flymake.el" href="http://www.emacswiki.org/emacs?action=rss;rcidonly=init-flymake.el">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki with page content" href="http://www.emacswiki.org/emacs/full.rss">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki with page content and diff" href="http://www.emacswiki.org/emacs/full-diff.rss">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki including minor differences" href="http://www.emacswiki.org/emacs/minor-edits.rss">
<LINK rel="alternate" type="application/rss+xml" title="Changes for init-flymake.el only" href="http://www.emacswiki.org/emacs?action=rss;rcidonly=init-flymake.el"></HEAD><BODY class="http://www.emacswiki.org/emacs"><DIV class="header"><A class="logo" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96"><IMG class="logo" src="./init-flymake_files/emacs_logo.png" alt="[首頁]"></A><SPAN class="gotobar bar"><A class="local" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96">網站地圖</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%9c%80%e8%bf%91%e6%9b%b4%e6%96%b0">最近更新</A> <A class="local" href="http://www.emacswiki.org/emacs/News">News</A> <A class="local" href="http://www.emacswiki.org/emacs/ElispArea">ElispArea</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%95%99%e5%af%bc">教导</A> </SPAN>
<!-- Google CSE Search Box Begins  -->
<FORM class="tiny" action="http://www.google.com/cse" id="searchbox_004774160799092323420:6-ff2s0o6yi"><P>
<INPUT type="hidden" name="cx" value="004774160799092323420:6-ff2s0o6yi">
<INPUT type="text" name="q" size="25" style="background-image: url(http://www.google.com/cse/intl/en/images/google_custom_search_watermark.gif); background-attachment: initial; background-origin: initial; background-clip: initial; background-color: rgb(255, 255, 255); background-position: 0% 50%; background-repeat: no-repeat no-repeat; ">
<INPUT type="submit" name="sa" value="Search">
</P><INPUT name="siteurl" type="hidden" value="www.emacswiki.org/emacs/init-flymake.el"></FORM>
<SCRIPT type="text/javascript" src="./init-flymake_files/brand"></SCRIPT>
<!-- Google CSE Search Box Ends -->
<H1><A title="按下即可以搜尋參考至本頁的資料" rel="nofollow" href="http://www.google.com/cse?cx=004774160799092323420:6-ff2s0o6yi&q=%22init-flymake.el%22">init-flymake.el</A></H1></DIV><DIV class="wrapper"><DIV class="content browse"><P class="download"><A href="http://www.emacswiki.org/emacs/download/init-flymake.el">Download</A></P><PRE class="code"><SPAN class="linecomment">;;; init-flymake.el --- Flymake configuration</SPAN>

<SPAN class="linecomment">;; Filename: init-flymake.el</SPAN>
<SPAN class="linecomment">;; Description: Flymake configuration</SPAN>
<SPAN class="linecomment">;; Author: Andy Stewart lazycat.manatee@gmail.com</SPAN>
<SPAN class="linecomment">;; Maintainer: Andy Stewart lazycat.manatee@gmail.com</SPAN>
<SPAN class="linecomment">;; Copyright (C) 2008, 2009, Andy Stewart, all rights reserved.</SPAN>
<SPAN class="linecomment">;; Created: 2008-10-20 09:43:11</SPAN>
<SPAN class="linecomment">;; Version: 0.1</SPAN>
<SPAN class="linecomment">;; Last-Updated: 2008-10-20 09:43:11</SPAN>
<SPAN class="linecomment">;;           By: Andy Stewart</SPAN>
<SPAN class="linecomment">;; URL:</SPAN>
<SPAN class="linecomment">;; Keywords: flymake</SPAN>
<SPAN class="linecomment">;; Compatibility: GNU Emacs 23.0.60.1</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; Features that might be required by this library:</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>

<SPAN class="linecomment">;;; This file is NOT part of GNU Emacs</SPAN>

<SPAN class="linecomment">;;; License</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; This program is free software; you can redistribute it and/or modify</SPAN>
<SPAN class="linecomment">;; it under the terms of the GNU General Public License as published by</SPAN>
<SPAN class="linecomment">;; the Free Software Foundation; either version 3, or (at your option)</SPAN>
<SPAN class="linecomment">;; any later version.</SPAN>

<SPAN class="linecomment">;; This program is distributed in the hope that it will be useful,</SPAN>
<SPAN class="linecomment">;; but WITHOUT ANY WARRANTY; without even the implied warranty of</SPAN>
<SPAN class="linecomment">;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the</SPAN>
<SPAN class="linecomment">;; GNU General Public License for more details.</SPAN>

<SPAN class="linecomment">;; You should have received a copy of the GNU General Public License</SPAN>
<SPAN class="linecomment">;; along with this program; see the file COPYING.  If not, write to</SPAN>
<SPAN class="linecomment">;; the Free Software Foundation, Inc., 51 Franklin Street, Fifth</SPAN>
<SPAN class="linecomment">;; Floor, Boston, MA 02110-1301, USA.</SPAN>

<SPAN class="linecomment">;;; Commentary:</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; Flymake configuration</SPAN>
<SPAN class="linecomment">;;</SPAN>

<SPAN class="linecomment">;;; Installation:</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; Put init-flymake.el to your load-path.</SPAN>
<SPAN class="linecomment">;; The load-path is usually ~/elisp/.</SPAN>
<SPAN class="linecomment">;; It's set in your ~/.emacs like this:</SPAN>
<SPAN class="linecomment">;; (add-to-list 'load-path (expand-file-name "~/elisp"))</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; And the following to your ~/.emacs startup file.</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; (require 'init-flymake)</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; No need more.</SPAN>

<SPAN class="linecomment">;;; Change log:</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;; 2008/10/20</SPAN>
<SPAN class="linecomment">;;      First released.</SPAN>
<SPAN class="linecomment">;;</SPAN>

<SPAN class="linecomment">;;; Acknowledgements:</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>

<SPAN class="linecomment">;;; TODO</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>
<SPAN class="linecomment">;;</SPAN>

<SPAN class="linecomment">;;; Require</SPAN>


<SPAN class="linecomment">;;; Code:</SPAN>

<SPAN class="linecomment">;; flymake</SPAN>
(dolist (hook (list
               'haskell-mode-hook
               'c-mode-hook
               'c++-mode-hook
               'java-mode-hook
               ))
  (add-hook hook 'flymake-find-file-hook))
<SPAN class="linecomment">;; flymake-shell</SPAN>
(add-hook 'sh-mode-hook 'flymake-shell-load)
<SPAN class="linecomment">;; flymake extension</SPAN>
(setq flymake-extension-use-showtip t)  <SPAN class="linecomment">;use `shotip' display error or warning.</SPAN>

(provide 'init-flymake)

<SPAN class="linecomment">;;; init-flymake.el ends here</SPAN></PRE></DIV><DIV class="wrapper close"></DIV></DIV><DIV class="footer"><HR><SPAN class="gotobar bar"><A class="local" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96">網站地圖</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%9c%80%e8%bf%91%e6%9b%b4%e6%96%b0">最近更新</A> <A class="local" href="http://www.emacswiki.org/emacs/News">News</A> <A class="local" href="http://www.emacswiki.org/emacs/ElispArea">ElispArea</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%95%99%e5%af%bc">教导</A> </SPAN><SPAN class="translation bar"><BR>  <A class="translation new" rel="nofollow" href="http://www.emacswiki.org/emacs?action=translate;id=init-flymake.el;missing=de_en_es_fr_it_ja_ko_pt_ru_se_zh">Add Translation</A></SPAN><SPAN class="edit bar"><BR> <A class="edit" accesskey="e" title="按此即可編輯此頁面" rel="nofollow" href="http://www.emacswiki.org/emacs?action=edit;id=init-flymake.el">編輯本頁</A> <A class="history" rel="nofollow" href="http://www.emacswiki.org/emacs?action=history;id=init-flymake.el">參閱其他版本</A> <A class="admin" rel="nofollow" href="http://www.emacswiki.org/emacs?action=admin;id=init-flymake.el">管理 Oddmuse</A></SPAN><SPAN class="time"><BR> 最後編輯於 2009-02-05 03:33 UTC 由 <A class="author" title="自 89.143.212.222.broad.cd.sc.dynamic.163data.com.cn" href="http://www.emacswiki.org/emacs/AndyStewart">AndyStewart</A></SPAN><DIV style="float:right; margin-left:1ex;">
<!-- Creative Commons License -->
<A href="http://creativecommons.org/licenses/GPL/2.0/"><IMG alt="CC-GNU GPL" style="border:none" src="./init-flymake_files/cc-GPL-a.png"></A>
<!-- /Creative Commons License -->
</DIV>

<!--
<rdf:RDF xmlns="http://web.resource.org/cc/"
 xmlns:dc="http://purl.org/dc/elements/1.1/"
 xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
<Work rdf:about="">
   <license rdf:resource="http://creativecommons.org/licenses/GPL/2.0/" />
  <dc:type rdf:resource="http://purl.org/dc/dcmitype/Software" />
</Work>

<License rdf:about="http://creativecommons.org/licenses/GPL/2.0/">
   <permits rdf:resource="http://web.resource.org/cc/Reproduction" />
   <permits rdf:resource="http://web.resource.org/cc/Distribution" />
   <requires rdf:resource="http://web.resource.org/cc/Notice" />
   <permits rdf:resource="http://web.resource.org/cc/DerivativeWorks" />
   <requires rdf:resource="http://web.resource.org/cc/ShareAlike" />
   <requires rdf:resource="http://web.resource.org/cc/SourceCode" />
</License>
</rdf:RDF>
-->

<P class="legal">
This work is licensed to you under version 2 of the
<A href="http://www.gnu.org/">GNU</A> <A href="http://www.emacswiki.org/GPL">General Public License</A>.
Alternatively, you may choose to receive this work under any other
license that grants the right to use, copy, modify, and/or distribute
the work, as long as that license imposes the restriction that
derivative works have to grant the same rights and impose the same
restriction. For example, you may choose to receive this work under
the
<A href="http://www.gnu.org/">GNU</A>
<A href="http://www.emacswiki.org/FDL">Free Documentation License</A>, the
<A href="http://creativecommons.org/">CreativeCommons</A>
<A href="http://creativecommons.org/licenses/sa/1.0/">ShareAlike</A>
License, the XEmacs manual license, or
<A href="http://www.emacswiki.org/OLD">similar licenses</A>.
</P>
</DIV>


</BODY></HTML>