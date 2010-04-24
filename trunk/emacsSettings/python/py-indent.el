<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<!-- saved from url=(0043)http://www.emacswiki.org/emacs/py-indent.el -->
<HTML xmlns="http://www.w3.org/1999/xhtml"><HEAD><META http-equiv="Content-Type" content="text/html; charset=UTF-8"><TITLE>EmacsWiki: py-indent.el</TITLE><LINK rel="alternate" type="application/wiki" title="編輯本頁" href="http://www.emacswiki.org/emacs?action=edit;id=py-indent.el"><LINK type="text/css" rel="stylesheet" href="./py-indent_files/wiki.css"><META name="robots" content="INDEX,FOLLOW"><LINK rel="alternate" type="application/rss+xml" title="EmacsWiki" href="http://www.emacswiki.org/emacs?action=rss"><LINK rel="alternate" type="application/rss+xml" title="EmacsWiki: py-indent.el" href="http://www.emacswiki.org/emacs?action=rss;rcidonly=py-indent.el">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki with page content" href="http://www.emacswiki.org/emacs/full.rss">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki with page content and diff" href="http://www.emacswiki.org/emacs/full-diff.rss">
<LINK rel="alternate" type="application/rss+xml" title="Emacs Wiki including minor differences" href="http://www.emacswiki.org/emacs/minor-edits.rss">
<LINK rel="alternate" type="application/rss+xml" title="Changes for py-indent.el only" href="http://www.emacswiki.org/emacs?action=rss;rcidonly=py-indent.el"></HEAD><BODY class="http://www.emacswiki.org/emacs"><DIV class="header"><A class="logo" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96"><IMG class="logo" src="./py-indent_files/emacs_logo.png" alt="[首頁]"></A><SPAN class="gotobar bar"><A class="local" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96">網站地圖</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%9c%80%e8%bf%91%e6%9b%b4%e6%96%b0">最近更新</A> <A class="local" href="http://www.emacswiki.org/emacs/News">News</A> <A class="local" href="http://www.emacswiki.org/emacs/ElispArea">ElispArea</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%95%99%e5%af%bc">教导</A> </SPAN>
<!-- Google CSE Search Box Begins  -->
<FORM class="tiny" action="http://www.google.com/cse" id="searchbox_004774160799092323420:6-ff2s0o6yi"><P>
<INPUT type="hidden" name="cx" value="004774160799092323420:6-ff2s0o6yi">
<INPUT type="text" name="q" size="25" style="background-image: url(http://www.google.com/cse/intl/en/images/google_custom_search_watermark.gif); background-attachment: initial; background-origin: initial; background-clip: initial; background-color: rgb(255, 255, 255); background-position: 0% 50%; background-repeat: no-repeat no-repeat; ">
<INPUT type="submit" name="sa" value="Search">
</P><INPUT name="siteurl" type="hidden" value="www.emacswiki.org/emacs/py-indent.el"></FORM>
<SCRIPT type="text/javascript" src="./py-indent_files/brand"></SCRIPT>
<!-- Google CSE Search Box Ends -->
<H1><A title="按下即可以搜尋參考至本頁的資料" rel="nofollow" href="http://www.google.com/cse?cx=004774160799092323420:6-ff2s0o6yi&q=%22py-indent.el%22">py-indent.el</A></H1></DIV><DIV class="wrapper"><DIV class="content browse"><P class="download"><A href="http://www.emacswiki.org/emacs/download/py-indent.el">Download</A></P><PRE class="code"><SPAN class="linecomment">;;; py-indent.el --- Python indentation with annotations</SPAN>

<SPAN class="linecomment">;; Copyright (C) 2008,2009 Davis Herring</SPAN>

<SPAN class="linecomment">;; Author: Davis Herring &lt;herring@lanl.gov&gt;</SPAN>
<SPAN class="linecomment">;; Keywords: python indent</SPAN>
<SPAN class="linecomment">;; Updated: January 13 2009</SPAN>
<SPAN class="linecomment">;; Version: 0.3</SPAN>

<SPAN class="linecomment">;; This file is not part of GNU Emacs.</SPAN>

<SPAN class="linecomment">;; This program is free software; you can redistribute it and/or</SPAN>
<SPAN class="linecomment">;; modify it under the terms of the GNU General Public License as</SPAN>
<SPAN class="linecomment">;; published by the Free Software Foundation; either version 2, or (at</SPAN>
<SPAN class="linecomment">;; your option) any later version.</SPAN>

<SPAN class="linecomment">;; This program is distributed in the hope that it will be useful, but</SPAN>
<SPAN class="linecomment">;; WITHOUT ANY WARRANTY; without even the implied warranty of</SPAN>
<SPAN class="linecomment">;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU</SPAN>
<SPAN class="linecomment">;; General Public License for more details.</SPAN>

<SPAN class="linecomment">;; You should have received a copy of the GNU General Public License</SPAN>
<SPAN class="linecomment">;; along with this program; see the file COPYING.  If not, write to</SPAN>
<SPAN class="linecomment">;; the Free Software Foundation, Inc., 59 Temple Place - Suite 330,</SPAN>
<SPAN class="linecomment">;; Boston, MA 02111-1307, USA.</SPAN>

<SPAN class="linecomment">;;; Commentary:</SPAN>

<SPAN class="linecomment">;; This package provides support for annotating Python code with C-like block</SPAN>
<SPAN class="linecomment">;; delimiters (in Python comments) that allow the indentation of the file to</SPAN>
<SPAN class="linecomment">;; be reconstructed after modification or damage.  Annotations may be</SPAN>
<SPAN class="linecomment">;; generated automatically from the current indentation; the user may freely</SPAN>
<SPAN class="linecomment">;; add or remove annotations to change the extent of blocks, and then apply</SPAN>
<SPAN class="linecomment">;; the annotations to update or restore the indentation.  Entry points:</SPAN>

<SPAN class="linecomment">;; `pyi-annotate' - add annotations to the buffer based on indentation</SPAN>
<SPAN class="linecomment">;; `pyi-unannotate' - remove all annotations</SPAN>
<SPAN class="linecomment">;; `pyi-apply' - recalculate all indentation from annotations</SPAN>
<SPAN class="linecomment">;; `pyi-line' - recalculate one line's indentation</SPAN>

<SPAN class="linecomment">;; The automatic annotation and unannotation try to be smart about placement</SPAN>
<SPAN class="linecomment">;; of the annotations and cleaning up blank spots where they are removed.</SPAN>

<SPAN class="linecomment">;; Warning: annotations, if used, must exist for a whole buffer, because a</SPAN>
<SPAN class="linecomment">;; region with none added can't be distinguished from one that should be</SPAN>
<SPAN class="linecomment">;; evenly indented!</SPAN>

<SPAN class="linecomment">;; This code attempts to work with both "python-mode.el" and "python.el".</SPAN>

<SPAN class="linecomment">;;; Bugs:</SPAN>

<SPAN class="linecomment">;; Strings that contain literal newlines and/or hashes can confuse the code,</SPAN>
<SPAN class="linecomment">;; especially with "python-mode.el" and with Emacs 21.  Escaping newlines or</SPAN>
<SPAN class="linecomment">;; hashes with backslashes helps in some cases.</SPAN>

<SPAN class="linecomment">;;; History:</SPAN>

<SPAN class="linecomment">;; Version 0.0, October 27 2008:</SPAN>
<SPAN class="linecomment">;;  - adding annotations only</SPAN>
<SPAN class="linecomment">;; Version 0.1, October 28 2008:</SPAN>
<SPAN class="linecomment">;;  - functional version for Emacs 22</SPAN>
<SPAN class="linecomment">;; Version 0.2, October 28 2008:</SPAN>
<SPAN class="linecomment">;;  - added support for Emacs 21 and python-mode.el</SPAN>
<SPAN class="linecomment">;; Version 0.2.1, October 29 2008:</SPAN>
<SPAN class="linecomment">;;  - fixed recognition of continuation lines in `pyi-line'</SPAN>
<SPAN class="linecomment">;;  - fixed annotating block-open lines that contain # in a string</SPAN>
<SPAN class="linecomment">;; Version 0.2.2, October 31 2008:</SPAN>
<SPAN class="linecomment">;;  - added default indent in case no python mode is loaded/helpful</SPAN>
<SPAN class="linecomment">;; Version 0.2.3, January 13 2009:</SPAN>
<SPAN class="linecomment">;;  - added warning/error for unmatched open/close annotations</SPAN>
<SPAN class="linecomment">;; Version 0.3, January 13 2009:</SPAN>
<SPAN class="linecomment">;;  - fixed `pyi-beginning-of-line' breaking at beginning of buffer</SPAN>
<SPAN class="linecomment">;;  - used 22/python.el features when available to deal with strings better</SPAN>
<SPAN class="linecomment">;;  - supplied `comment-start-skip' when needed (for python.el)</SPAN>
<SPAN class="linecomment">;;  - added errors to `debug-ignored-errors'</SPAN>

<SPAN class="linecomment">;;; Code:</SPAN>

<SPAN class="linecomment">;; Rules: Lines that end within () [] {} or with a \ outside of a comment or</SPAN>
<SPAN class="linecomment">;; string are joined to the next, and lines that contain only [ \t\f] and/or a</SPAN>
<SPAN class="linecomment">;; comment are ignored for indentation.  \ has \ syntax in either mode.</SPAN>

(eval-when-compile (require 'cl))	<SPAN class="linecomment">; incf, decf</SPAN>
(require 'newcomment)			<SPAN class="linecomment">; comment-indent</SPAN>

(defgroup pyi nil
  "<SPAN class="quote">Python indentation with annotations.</SPAN>"
  :prefix "<SPAN class="quote">pyi-</SPAN>")
(defcustom pyi-annotate-start "<SPAN class="quote">py{</SPAN>"
  "<SPAN class="quote">String to annotate the beginning of a block.</SPAN>"
  :type 'string
  :group 'pyi)
(put 'pyi-annotate-start 'safe-local-variable 'stringp)
(defcustom pyi-annotate-end "<SPAN class="quote">}py</SPAN>"
  "<SPAN class="quote">String to annotate the end of a block.</SPAN>"
  :type 'string
  :group 'pyi)
(put 'pyi-annotate-end 'safe-local-variable 'stringp)
(defcustom pyi-backup-indent 4
  "<SPAN class="quote">Offset per level of indentation.
Only used if no known Python mode has specified one.</SPAN>"
  :type 'integer
  :group 'pyi)
(put 'pyi-backup-indent 'safe-local-variable 'integerp)

(defconst pyi-whitespace "<SPAN class="quote"> \t\f</SPAN>")
(defconst pyi-whitespace-regexp (concat "<SPAN class="quote">[</SPAN>" pyi-whitespace "<SPAN class="quote">]*</SPAN>"))
(defconst pyi-comment-regexp (concat pyi-whitespace-regexp "<SPAN class="quote">#</SPAN>"))
(defconst pyi-empty-regexp (concat pyi-whitespace-regexp "<SPAN class="quote">$</SPAN>"))
(defconst pyi-line-end-regexp "<SPAN class="quote">\\(?:#.*\\)?$</SPAN>")
(defconst pyi-blank-regexp (concat pyi-whitespace-regexp pyi-line-end-regexp))

(defun pyi-indent ()
  "<SPAN class="quote">Get the offset for each level of indentation.
Checks for `python-indent' and `py-indent-offset'.
Uses `pyi-backup-indent' if neither is available.</SPAN>"
  (cond ((boundp 'python-indent) python-indent)
	((boundp 'py-indent-offset) py-indent-offset) (pyi-backup-indent)))

(defun pyi-how-many (re s e)
  "<SPAN class="quote">Return number of matches for RE between S and E.</SPAN>"
  (if (&gt;= emacs-major-version 22) (how-many re s e)
    (save-excursion
      (let ((n 0))
	(goto-char s) (while (re-search-forward re e t) (incf n)) n))))

(defun pyi-comment-p ()
  "<SPAN class="quote">Return non-nil if the current line bears a comment.
Leaves point somewhere on the line.</SPAN>"	<SPAN class="linecomment">; really, in comment or at end</SPAN>
  (if (fboundp 'syntax-ppss)
      (eq 'comment (syntax-ppss-context (syntax-ppss (line-end-position))))
    <SPAN class="linecomment">;; `comment-beginning' fails on # inside strings; even this fails if they</SPAN>
    <SPAN class="linecomment">;; contain the end of the current line.</SPAN>
    (forward-line 0)
    <SPAN class="linecomment">;; Emacs 22 python.el doesn't define `comment-start-skip'.</SPAN>
    (let ((comment-start-skip (or comment-start-skip "<SPAN class="quote">#+ *</SPAN>")))
      (comment-search-forward (line-end-position) t))))
<SPAN class="linecomment">;; (let ((e (line-end-position)))</SPAN>
<SPAN class="linecomment">;; (while</SPAN>
<SPAN class="linecomment">;;     (progn</SPAN>
<SPAN class="linecomment">;;       (re-search-forward pyi-whitespace-regexp)</SPAN>
<SPAN class="linecomment">;;       (unless (or (eq (char-after) ?#) (eolp))</SPAN>
<SPAN class="linecomment">;; 	(skip-syntax-forward ".w_()") ; don't skip whole paren-sexps here</SPAN>
<SPAN class="linecomment">;; 	(or (zerop (save-excursion (skip-syntax-forward "\"|")))</SPAN>
<SPAN class="linecomment">;; 	    (progn (forward-sexp) (&lt; (point) e))))))</SPAN>
<SPAN class="linecomment">;; (and (&lt; (point) e) (eq (char-after) ?#)))))</SPAN>

(defun pyi-beginning-of-line ()
  "<SPAN class="quote">Move to beginning of current logical line.
Absent python.el, point must not be within a string.</SPAN>"
  (interactive)
  (if (fboundp 'python-beginning-of-statement) (python-beginning-of-statement)
    (forward-line 0)			<SPAN class="linecomment">;get out of any comment</SPAN>
    (let ((parse-sexp-ignore-comments t))
      (while
	  (progn (ignore-errors (while t (up-list -1)))
		 (forward-line 0)
		 (and (not (bobp))
		      (save-excursion
			(backward-char)
			(and (eq (char-before) ?\\) (not (pyi-comment-p))))))
	(forward-line -1)))))		<SPAN class="linecomment">;advance past strings and parens</SPAN>

(defun pyi-skip-line ()
  "<SPAN class="quote">Advance past real content of current logical line.
Absent python.el, point must not be within a string.
Leave point before any trailing whitespace and/or comment.</SPAN>"
  (if (fboundp 'python-end-of-statement)
      (progn (python-end-of-statement)
	     (let ((syntax (syntax-ppss)))
	       (if (nth 4 syntax) (goto-char (nth 8 syntax))))
	     (skip-chars-backward pyi-whitespace))
    (while
	(unless (looking-at pyi-blank-regexp)
	  (re-search-forward pyi-whitespace-regexp)
	  (cond ((looking-at "<SPAN class="quote">\\\\$</SPAN>") (forward-line 1))
		((&gt; (skip-syntax-forward "<SPAN class="quote">.w_)</SPAN>") 0))
		(t (forward-sexp))) t))))

(defun pyi-end-of-line ()
  "<SPAN class="quote">Go to end of current logical line, before any trailing whitespace/comment.
Absent python.el, point must not be within a string.</SPAN>"
  (interactive)
  <SPAN class="linecomment">;; Find our way out of enclosing parens before proceeding forward.</SPAN>
  (unless (fboundp 'python-end-of-statement) (pyi-beginning-of-line))
  (pyi-skip-line))

(defun pyi-annotate ()
  "<SPAN class="quote">Annotate Python indentation in the current buffer.</SPAN>"
  (interactive "<SPAN class="quote">*</SPAN>")
  (save-excursion
    (save-restriction
      (widen) (goto-char (point-min))
      (and (or (save-excursion (search-forward pyi-annotate-start nil t))
	       (search-forward pyi-annotate-end nil t))
	   (error "<SPAN class="quote">Annotations already present; maybe change annotation style</SPAN>"))
      (re-search-forward pyi-whitespace-regexp)
      (if (&gt; (point) (point-min))
	  (error "<SPAN class="quote">Indentation at start of file</SPAN>"))
      (let ((tab-width 8) (is '(0)) last) <SPAN class="linecomment">;indentation stack, annotation spot</SPAN>
	(while (not (eobp))
	  <SPAN class="linecomment">;; Each iteration advances through a logical line.</SPAN>
	  (re-search-forward pyi-whitespace-regexp)
	  (let ((id (current-column)) (ci (car is)) up) <SPAN class="linecomment">;up: update `last'</SPAN>
	    (if (looking-at pyi-line-end-regexp)
		<SPAN class="linecomment">;; Even if it's just a comment, we want to close any enclosing</SPAN>
		<SPAN class="linecomment">;; block after it.</SPAN>
		(and (eq (char-after) ?#) (= id ci) (setq up t))
	      (setq up t)
	      (cond
	       ((&gt; id ci)
		(push id is)
		(save-excursion
		  (goto-char last)
		  (if (pyi-comment-p) (progn (end-of-line) (insert ?\ ))
		    (comment-indent))
		  (insert pyi-annotate-start)))
	       ((&lt; id ci)
		(let ((d 0))
		  (while (progn (pop is) (incf d) (&lt; id (car is))))
		  (if (/= id (car is)) (error "<SPAN class="quote">Unrecognized dedent</SPAN>"))
		  (save-excursion
		    <SPAN class="linecomment">;; It's important that we avoid inserting on our own line</SPAN>
		    <SPAN class="linecomment">;; where the excursion marker is.</SPAN>
		    (goto-char last) (insert ?\n) (indent-to id) (insert ?#)
		    <SPAN class="linecomment">;; d is always positive at this point.</SPAN>
		    (while (progn (insert ?\  pyi-annotate-end)
				  (&gt; (decf d) 0)))))))
	      (pyi-skip-line))
	    (forward-line 1)
	    (if up (setq last (1- (point))))))
	(when (setq is (cdr is))	<SPAN class="linecomment">; we ended in a block</SPAN>
	  (let ((fn (bolp)))		<SPAN class="linecomment">; final-newline status</SPAN>
	    (unless fn (insert ?\n)) (insert ?#)
	    (while (progn (insert ?\  pyi-annotate-end) (setq is (cdr is))))
	    (if fn (insert ?\n))))))))

(add-to-list 'debug-ignored-errors "<SPAN class="quote">^Annotations already present\&gt;</SPAN>")
(add-to-list 'debug-ignored-errors "<SPAN class="quote">^Indentation at start of file$</SPAN>")
(add-to-list 'debug-ignored-errors "<SPAN class="quote">^Unrecognized dedent$</SPAN>")

(defun pyi-unannotate ()
  "<SPAN class="quote">Remove indentation annotations in the current buffer.
They must lie inside comments, but need not be alone in them.</SPAN>"
  (interactive "<SPAN class="quote">*</SPAN>")
  (save-excursion
    (save-restriction
      (widen) (goto-char (point-min))
      (let ((re (concat "<SPAN class="quote">\\(?:\n?</SPAN>" pyi-whitespace-regexp "<SPAN class="quote">#\\)?\\(?:</SPAN>"
			pyi-whitespace-regexp "<SPAN class="quote">\\(?:</SPAN>"
			(regexp-quote pyi-annotate-start) "<SPAN class="quote">\\|</SPAN>"
			(regexp-quote pyi-annotate-end) "<SPAN class="quote">\\)\\)+</SPAN>")))
	(while (re-search-forward re nil t) (replace-match "<SPAN class="quote"></SPAN>"))))))

(defun pyi-apply ()
  "<SPAN class="quote">Apply indentation annotations in the current buffer.
Destroys all extant indentation except that of continuation lines.</SPAN>"
  (interactive "<SPAN class="quote">*</SPAN>")
  (save-excursion
    (save-restriction
      (widen) (goto-char (point-min))
      (let ((id 0) (res (regexp-quote pyi-annotate-start))
	    (ree (regexp-quote pyi-annotate-end)))
	(while (not (eobp))
	  <SPAN class="linecomment">;; Each iteration advances through a logical line.</SPAN>
	  (let ((p (point)) (c (looking-at pyi-comment-regexp))
		(e (looking-at pyi-empty-regexp)) (i id)
		(lep (progn (pyi-skip-line) (line-end-position))))
	    (unless (wholenump (incf id (- (pyi-how-many res p lep)
					   (pyi-how-many ree p lep))))
	      (message "<SPAN class="quote">Unexpected end annotation here</SPAN>") (sit-for 2)
	      (error "<SPAN class="quote">Unexpected end annotation</SPAN>"))
	    <SPAN class="linecomment">;; Now go back and indent if the line wasn't empty, to the old</SPAN>
	    <SPAN class="linecomment">;; value unless the line is only a comment and the indent</SPAN>
	    <SPAN class="linecomment">;; decreased (a block-close comment).</SPAN>
	    (unless e
	      (save-excursion
		(goto-char p)
		(indent-line-to (* (if c (min i id) i) (pyi-indent))))))
	  (forward-line 1))
	(unless (zerop id) (message "<SPAN class="quote">Warning: unmatched start annotation</SPAN>"))))))

(add-to-list 'debug-ignored-errors "<SPAN class="quote">^Unexpected end annotation$</SPAN>")

(defun pyi-calculate ()
  "<SPAN class="quote">Get indentation for current line based on indentation annotations.
Other non-blank, non-comment lines are assumed to be properly indented.
Continuation lines are simply indented half a level past their starts.
This function does not move point.</SPAN>"
  (save-excursion
    (forward-line 0)
    (let ((p (point)) (res (regexp-quote pyi-annotate-start))
	  (ree (regexp-quote pyi-annotate-end)))
      (pyi-beginning-of-line)
      (cond ((bobp) 0)
	    ((/= p (point)) (+ (/ (pyi-indent) 2) (current-indentation)))
	    (t (while (progn (forward-line -1) (pyi-beginning-of-line)
			     (looking-at pyi-comment-regexp)))
	       (+ (* (pyi-indent) (- (pyi-how-many res (point) p)
				    (pyi-how-many ree (point) p)))
		  (current-indentation)))))))

(defun pyi-line ()
  "<SPAN class="quote">Indent current line based on indentation annotations.
Other non-blank, non-comment lines are assumed to be properly indented.</SPAN>"
  (interactive "<SPAN class="quote">*</SPAN>")
  (save-excursion (indent-line-to (pyi-calculate))))

(provide 'py-indent)

<SPAN class="linecomment">;; py-indent.el ends here</SPAN></PRE></DIV><DIV class="wrapper close"></DIV></DIV><DIV class="footer"><HR><SPAN class="gotobar bar"><A class="local" href="http://www.emacswiki.org/emacs/%e7%b6%b2%e7%ab%99%e5%9c%b0%e5%9c%96">網站地圖</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%9c%80%e8%bf%91%e6%9b%b4%e6%96%b0">最近更新</A> <A class="local" href="http://www.emacswiki.org/emacs/News">News</A> <A class="local" href="http://www.emacswiki.org/emacs/ElispArea">ElispArea</A> <A class="local" href="http://www.emacswiki.org/emacs/%e6%95%99%e5%af%bc">教导</A> </SPAN><SPAN class="translation bar"><BR>  <A class="translation new" rel="nofollow" href="http://www.emacswiki.org/emacs?action=translate;id=py-indent.el;missing=de_en_es_fr_it_ja_ko_pt_ru_se_zh">Add Translation</A></SPAN><SPAN class="edit bar"><BR> <A class="edit" accesskey="e" title="按此即可編輯此頁面" rel="nofollow" href="http://www.emacswiki.org/emacs?action=edit;id=py-indent.el">編輯本頁</A> <A class="history" rel="nofollow" href="http://www.emacswiki.org/emacs?action=history;id=py-indent.el">參閱其他版本</A> <A class="admin" rel="nofollow" href="http://www.emacswiki.org/emacs?action=admin;id=py-indent.el">管理 Oddmuse</A></SPAN><SPAN class="time"><BR> 最後編輯於 2009-01-13 22:50 UTC 由 <A class="author" title="自 proxyout.lanl.gov" href="http://www.emacswiki.org/emacs/DavisHerring">DavisHerring</A> <A class="diff" rel="nofollow" href="http://www.emacswiki.org/emacs?action=browse;diff=2;id=py-indent.el">(比較差異)</A></SPAN><DIV style="float:right; margin-left:1ex;">
<!-- Creative Commons License -->
<A href="http://creativecommons.org/licenses/GPL/2.0/"><IMG alt="CC-GNU GPL" style="border:none" src="./py-indent_files/cc-GPL-a.png"></A>
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