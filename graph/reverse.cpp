t e m p l a t e   < t y p e n a m e   T >  
 d i g r a p h < T >   r e v e r s e ( c o n s t   d i g r a p h < T >   & g )   {  
     d i g r a p h < T >   r g ( g . n ) ;  
     f o r   ( a u t o   & e   :   g . e d g e s )   {  
         r g . a d d ( e . t o ,   e . f r o m ,   e . c o s t ) ;  
     }  
     r e t u r n   r g ;  
 } 