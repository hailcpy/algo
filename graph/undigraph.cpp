t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   u n d i g r a p h   :   p u b l i c   g r a p h < T >   {  
     p u b l i c :  
     u s i n g   g r a p h < T > : : e d g e s ;  
     u s i n g   g r a p h < T > : : g ;  
     u s i n g   g r a p h < T > : : n ;  
  
     u n d i g r a p h ( i n t   n )   :   g r a p h < T > ( n )   {  
     }  
  
     v o i d   a d d ( i n t   f r o m ,   i n t   t o ,   T   c o s t   =   1 )   {  
         a s s e r t ( 0   < =   f r o m   & &   f r o m   <   n   & &   0   < =   t o   & &   t o   <   n ) ;  
         g [ f r o m ] . p u s h _ b a c k ( e d g e s . s i z e ( ) ) ;  
         g [ t o ] . p u s h _ b a c k ( e d g e s . s i z e ( ) ) ;  
         e d g e s . p u s h _ b a c k ( { f r o m ,   t o ,   c o s t } ) ;  
     }  
 } ; 