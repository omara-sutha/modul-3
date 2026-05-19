#include <stdio.h>

int main() {
    int p,b,k,n,i,j,x,b2,k2;
    double A[10][10],B[10][10],C[10][10],U[10],V[10],s,d;
    
    while(1) {
        printf("\n========================================\n");
        printf("        OPERASI MATRIKS & VEKTOR\n");
        printf("========================================\n");
        printf("1. Operasi Matriks\n");
        printf("2. Operasi Vektor\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&p);
        if(p==3) { printf("\nTerima kasih!\n"); break; }
      
        if(p==1) {
            printf("\n--- OPERASI MATRIKS ---\n");
            printf("1. Penjumlahan\n");
            printf("2. Perkalian\n");
            printf("3. Inverse\n");
            printf("4. Transpose\n");
            printf("5. Inner Product\n");
            printf("Pilih: ");
            scanf("%d",&p);
            if(p<1||p>5) { printf("Pilihan tidak valid!\n"); continue; }
            
            printf("Ukuran matriks (baris kolom): ");
            scanf("%d%d",&b,&k);
            if(b<=0||k<=0||b>10||k>10) { printf("Error: Ukuran 1-10!\n"); continue; }
            
            // Input Matriks A
            printf("\nMatriks A:\n");
            for(i=0;i<b;i++) for(j=0;j<k;j++) { printf("A[%d][%d] = ",i,j); scanf("%lf",&A[i][j]); }
            
            // Tampilkan Matriks A
            printf("\nA = ");
            for(i=0;i<b;i++) { printf("["); for(j=0;j<k;j++) { printf("%.0lf",A[i][j]); if(j<k-1) printf("  "); } printf("]"); if(i<b-1) printf("\n    "); }
            
            // Input Matriks B
            if(p==1||p==5) {
                printf("\n\nMatriks B:\n");
                for(i=0;i<b;i++) for(j=0;j<k;j++) { printf("B[%d][%d] = ",i,j); scanf("%lf",&B[i][j]); }
                printf("\nB = ");
                for(i=0;i<b;i++) { printf("["); for(j=0;j<k;j++) { printf("%.0lf",B[i][j]); if(j<k-1) printf("  "); } printf("]"); if(i<b-1) printf("\n    "); }
            }
            else if(p==2) {
                printf("\nUkuran matriks B (baris kolom): ");
                scanf("%d%d",&b2,&k2);
                if(k!=b2) { printf("\nError: Kolom A(%d) != baris B(%d)!\n",k,b2); continue; }
                printf("\nMatriks B:\n");
                for(i=0;i<b2;i++) for(j=0;j<k2;j++) { printf("B[%d][%d] = ",i,j); scanf("%lf",&B[i][j]); }
                printf("\nB = ");
                for(i=0;i<b2;i++) { printf("["); for(j=0;j<k2;j++) { printf("%.0lf",B[i][j]); if(j<k2-1) printf("  "); } printf("]"); if(i<b2-1) printf("\n    "); }
            }
            
            printf("\n");
            
            if(p==1) { // PENJUMLAHAN
                printf("\nHasil Penjumlahan (A + B):\nC = ");
                for(i=0;i<b;i++) { printf("["); for(j=0;j<k;j++) printf("%.2lf%s",A[i][j]+B[i][j],j<k-1?"  ":""); printf("]"); if(i<b-1) printf("\n    "); }
                printf("\n");
            }
            else if(p==2) { // PERKALIAN
                printf("\nHasil Perkalian (A x B):\nC = ");
                for(i=0;i<b;i++) { 
                    printf("[");
                    for(j=0;j<k2;j++) { 
                        s=0; for(x=0;x<k;x++) s+=A[i][x]*B[x][j]; 
                        printf("%.2lf%s",s,j<k2-1?"  ":""); 
                    } 
                    printf("]"); 
                    if(i<b-1) printf("\n    "); 
                }
                printf("\n");
            }
            else if(p==3) { // INVERSE (2x2)
                if(b!=2||k!=2) { printf("\nError: Inverse hanya untuk matriks 2x2!\n"); continue; }
                d=A[0][0]*A[1][1]-A[0][1]*A[1][0];
                if(d==0) { printf("\nError: Matriks singular!\n"); continue; }
                printf("\nHasil Inverse (A⁻¹):\nA⁻¹ = ");
                printf("[%.2lf  %.2lf]\n     [%.2lf  %.2lf]\n",A[1][1]/d,-A[0][1]/d,-A[1][0]/d,A[0][0]/d);
            }
            else if(p==4) { // TRANSPOSE
                printf("\nHasil Transpose (Aᵀ):\nAᵀ = ");
                for(i=0;i<k;i++) { printf("["); for(j=0;j<b;j++) printf("%.0lf%s",A[j][i],j<b-1?"  ":""); printf("]"); if(i<k-1) printf("\n     "); }
                printf("\n");
            }
            else if(p==5) { // INNER PRODUCT
                for(s=0,i=0;i<b;i++) for(j=0;j<k;j++) s+=A[i][j]*B[i][j];
                printf("\nInner Product = %.2lf\n",s);
            }
        }
        
        else if(p==2) {
            printf("\n--- OPERASI VEKTOR ---\n");
            printf("1. Penjumlahan\n");
            printf("2. Pengurangan\n");
            printf("3. Dot Product\n");
            printf("4. Cross Product\n");
            printf("Pilih: ");
            scanf("%d",&p);
            if(p<1||p>4) { printf("Pilihan tidak valid!\n"); continue; }
            
            printf("Dimensi vektor: ");
            scanf("%d",&n);
            if(n<=0||n>10) { printf("Error: Dimensi 1-10!\n"); continue; }
            if(p==4&&n!=3) { printf("Error: Cross product hanya untuk 3 dimensi!\n"); continue; }
            
            // Input Vektor U
            printf("\nVektor U:\n");
            for(i=0;i<n;i++) { printf("U[%d] = ",i); scanf("%lf",&U[i]); }
            printf("\nU = [");
            for(i=0;i<n;i++) { printf("%.0lf",U[i]); if(i<n-1) printf(", "); }
            printf("]");
            
            // Input Vektor V
            printf("\n\nVektor V:\n");
            for(i=0;i<n;i++) { printf("V[%d] = ",i); scanf("%lf",&V[i]); }
            printf("\nV = [");
            for(i=0;i<n;i++) { printf("%.0lf",V[i]); if(i<n-1) printf(", "); }
            printf("]\n");
            
            // Operasi Vektor
            if(p==1) { // PENJUMLAHAN
                printf("\nHasil Penjumlahan (U + V):\nW = [");
                for(i=0;i<n;i++) printf("%.2lf%s",U[i]+V[i],i<n-1?", ":"");
                printf("]\n");
            }
            else if(p==2) { // PENGURANGAN
                printf("\nHasil Pengurangan (U - V):\nW = [");
                for(i=0;i<n;i++) printf("%.2lf%s",U[i]-V[i],i<n-1?", ":"");
                printf("]\n");
            }
            else if(p==3) { // DOT PRODUCT
                for(s=0,i=0;i<n;i++) s+=U[i]*V[i];
                printf("\nDot Product (U · V) = %.2lf\n",s);
            }
            else if(p==4) { // CROSS PRODUCT
                printf("\nHasil Cross Product (U × V):\nW = [%.2lf, %.2lf, %.2lf]\n",
                    U[1]*V[2]-U[2]*V[1],
                    U[2]*V[0]-U[0]*V[2],
                    U[0]*V[1]-U[1]*V[0]);
            }
        }
        else printf("\nPilihan tidak valid!\n");
    }
    return 0;
}